#ifndef QMLACCESS_H
#define QMLACCESS_H
#include <gconfitem.h>

#include <QDeclarativeView>
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QSettings>
#include <QDebug>

#include "listkey.h"
#include "entity.h"

class QMLAccess : public QDeclarativeView
{
	Q_OBJECT
public:
    explicit QMLAccess(QWidget *parent = 0);
	enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };
    void setOrientation(ScreenOrientation orientation);
	
public slots:

    void debug(QString msg);

    void enterDirectory(QString destination);
    void leaveDirectory(QString actualDir);

    void getContentOf(QString destination);

    QString shortname(QString destination);
    QString parentDir(QString destination);

    void getBoolKey(QString key);
    void getIntKey(QString key);
    void getDoubleKey(QString key);
    void getStringKey(QString key);
    void getStringListKey(QString key);

    void setKey(QString key, QVariant value);
    void unsetKey(QString key);

    void removeValueFromList(int index);
    void addValueToList();
    void modifyContentOfList(QString newValue, int index);
    void setListKeys(QString key);

private:
    QDeclarativeContext *m_context;
    QSettings *settings;
    QList<QObject*> currentListValues;
};

#endif // QMLACCESS_H
