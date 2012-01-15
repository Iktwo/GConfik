/****************************************************************************
** Meta object code from reading C++ file 'qmlaccess.h'
**
** Created: Fri 13. Jan 18:03:07 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qmlaccess.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmlaccess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMLAccess[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x0a,
      42,   30,   10,   10, 0x0a,
      76,   66,   10,   10, 0x0a,
     100,   30,   10,   10, 0x0a,
     130,   30,  122,   10, 0x0a,
     149,   30,  122,   10, 0x0a,
     172,  168,   10,   10, 0x0a,
     192,  168,   10,   10, 0x0a,
     211,  168,   10,   10, 0x0a,
     233,  168,   10,   10, 0x0a,
     255,  168,   10,   10, 0x0a,
     291,  281,   10,   10, 0x0a,
     316,  168,   10,   10, 0x0a,
     340,  334,   10,   10, 0x0a,
     365,   10,   10,   10, 0x0a,
     397,  382,   10,   10, 0x0a,
     430,  168,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMLAccess[] = {
    "QMLAccess\0\0msg\0debug(QString)\0destination\0"
    "enterDirectory(QString)\0actualDir\0"
    "leaveDirectory(QString)\0getContentOf(QString)\0"
    "QString\0shortname(QString)\0"
    "parentDir(QString)\0key\0getBoolKey(QString)\0"
    "getIntKey(QString)\0getDoubleKey(QString)\0"
    "getStringKey(QString)\0getStringListKey(QString)\0"
    "key,value\0setKey(QString,QVariant)\0"
    "unsetKey(QString)\0index\0"
    "removeValueFromList(int)\0addValueToList()\0"
    "newValue,index\0modifyContentOfList(QString,int)\0"
    "setListKeys(QString)\0"
};

const QMetaObject QMLAccess::staticMetaObject = {
    { &QDeclarativeView::staticMetaObject, qt_meta_stringdata_QMLAccess,
      qt_meta_data_QMLAccess, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMLAccess::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMLAccess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMLAccess::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMLAccess))
        return static_cast<void*>(const_cast< QMLAccess*>(this));
    return QDeclarativeView::qt_metacast(_clname);
}

int QMLAccess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: debug((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: enterDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: leaveDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: getContentOf((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { QString _r = shortname((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = parentDir((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: getBoolKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: getIntKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: getDoubleKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: getStringKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: getStringListKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: setKey((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 12: unsetKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: removeValueFromList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: addValueToList(); break;
        case 15: modifyContentOfList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: setListKeys((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
