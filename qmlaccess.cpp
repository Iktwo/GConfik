#include "qmlaccess.h"
#include <QDebug>
#include <QStringList>

QMLAccess::QMLAccess(QWidget *parent) :
    QDeclarativeView(parent)
{
    m_context = rootContext();
    m_context->setContextProperty("wMain", this);

    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    setSource(QUrl("qrc:/qml/main.qml"));

    getContentOf("/");
}

void QMLAccess::debug(QString msg){
    qDebug() << msg;
}

void QMLAccess::enterDirectory(QString destination){
    getContentOf(destination);
}

void QMLAccess::leaveDirectory(QString actualDir){
    if (actualDir.length()>1){

        /*** Calculate parent directory ***/

        //debug("Actual dir: "+actualDir);
        //debug("Actual dir /'s last index "+QString::number(actualDir.lastIndexOf("/")));

        QString destination = actualDir.mid(0,actualDir.lastIndexOf("/"));

        /*** Get content of directory ***/
        if (destination.length()==0){
            getContentOf("/");
        }else{
            getContentOf(destination);
        }

    }
}

QString QMLAccess::shortname(QString destination){
    //debug("Shortname of "+destination);
    if (destination.length()>1){
        int x = destination.lastIndexOf("/");
        return destination.mid(x+1);
    }else{
        return destination;
    }
}

QString QMLAccess::parentDir(QString destination){
    if (destination.length()>1){
        int x = destination.lastIndexOf("/");
        return destination.mid(0,x);
    }else{
        return destination;
    }
}

void QMLAccess::getContentOf(QString destination){
    /*** Get the content (dirs and entries) of a directory ***/

    QList<QObject*> dataList;

    //debug("Getting content of "+destination);

    /*** Create a GConfItem to access dirs ***/

    GConfItem readDir(destination);

    /*** Create a list with all dirs and a list with all entries ***/

    QStringList dirs = readDir.listDirs();
    QStringList entries = readDir.listEntries();

    //debug("Total "+destination+" Dirs: "+QString::number(dirs.count()));
    //debug("Total "+destination+" Entries: "+QString::number(entries.count()));

    for (int var = 0; var < dirs.count(); ++var) {
        //debug("Dir: "+dirs.at(var));
        if (destination=="/"){
            if (dirs.at(var)!="/schemas"){
                dataList.append(new Entity(dirs.at(var),"false",""));
            }
        }else{
            dataList.append(new Entity(dirs.at(var),"false",""));
        }
    }

    for (int var = 0; var < entries.count(); ++var) {
        //debug("Entry: "+entries.at(var));
        GConfItem entry(entries.at(var));

        /*** Get the key's data type using QMetaType ***/

        /*** http://developer.qt.nokia.com/doc/qt-4.8/qmetatype.html#Type-enum ***/

        /*
          Void = 0
          Bool = 1
          Int = 2
          Double = 6
          QString = 10
          QStringList = 11
        */

        int type = entry.value().type();
        debug("Type: "+QString::number(type));

        switch(type){
        case 0:
            dataList.append(new Entity(entries.at(var),"true","Void"));
            break;
        case 1:
            dataList.append(new Entity(entries.at(var),"true","Bool"));
            break;
        case 2:
            dataList.append(new Entity(entries.at(var),"true","Int"));
            break;
        case 6:
            dataList.append(new Entity(entries.at(var),"true","Double"));
            break;
        case 10:
            dataList.append(new Entity(entries.at(var),"true","String"));
            break;
        case 11:
            dataList.append(new Entity(entries.at(var),"true","StringList"));
            break;
        }
    }
    m_context->setContextProperty("actualDir", destination);
    m_context->setContextProperty("gconfKeysModel", QVariant::fromValue(dataList));
}

void QMLAccess::getBoolKey(QString key){
    GConfItem entry(key);
    m_context->setContextProperty("keyName", shortname(key));
    m_context->setContextProperty("boolValue", entry.value().toBool());
}

void QMLAccess::unsetKey(QString key){
    GConfItem entry(key);
    entry.unset();
}

void QMLAccess::setKey(QString key, QVariant value){
    GConfItem entry(key);
    entry.set(value);
}

void QMLAccess::getStringKey(QString key){
    GConfItem entry(key);
    m_context->setContextProperty("keyName", shortname(key));
    m_context->setContextProperty("stringValue", entry.value().toString());
}

void QMLAccess::getStringListKey(QString key){
    GConfItem entry(key);
    QStringList entries = entry.value().toStringList();

    currentListValues.clear();

    for (int var = 0; var < entries.count(); ++var) {
        currentListValues.append(new ListKey(entries.at(var),QString::number(var)));
    }

    m_context->setContextProperty("keyName", shortname(key));
    m_context->setContextProperty("listKeys", QVariant::fromValue(currentListValues));
}

void QMLAccess::removeValueFromList(int index){
    currentListValues.removeAt(index);
    m_context->setContextProperty("listKeys", QVariant::fromValue(currentListValues));
}

void QMLAccess::addValueToList(){
    if (currentListValues.count()>1){
        QString x = currentListValues.last()->property("index").toString();
        currentListValues.append(new ListKey("",x));
    }else{
        currentListValues.append(new ListKey("","0"));
    }
    m_context->setContextProperty("listKeys", QVariant::fromValue(currentListValues));
}

void QMLAccess::modifyContentOfList(QString newValue, int index){
    /*FIXME: Anda pues, actualiza el valor, necesitas el index!*/

    //currentListValues.removeAt(index);

    currentListValues.at(index)->setProperty("value",newValue);

    //currentListValues.insert(index,);
}

void QMLAccess::setListKeys(QString key){
    GConfItem entry(key);

    QStringList values;
    for (int var = 0; var < currentListValues.count(); ++var) {
        values.append(currentListValues.at(var)->property("value").toString());
    }

    entry.set(values);
}

void QMLAccess::getIntKey(QString key){
    GConfItem entry(key);
    m_context->setContextProperty("keyName", shortname(key));
    m_context->setContextProperty("intValue", entry.value().toString());
}

void QMLAccess::getDoubleKey(QString key){
    GConfItem entry(key);
    m_context->setContextProperty("keyName", shortname(key));
    m_context->setContextProperty("doubleValue", entry.value().toString());
}
