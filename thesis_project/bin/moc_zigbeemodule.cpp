/****************************************************************************
** Meta object code from reading C++ file 'zigbeemodule.h'
**
** Created: Sun Sep 14 15:51:51 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modules/zigbeemodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zigbeemodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZigbeeModule[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      26,   13,   13,   13, 0x0a,
      47,   34,   13,   13, 0x0a,
      95,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ZigbeeModule[] = {
    "ZigbeeModule\0\0broadcast()\0stops()\0"
    "name,target,\0"
    "changePortSetting(QString,QString,PortSettings)\0"
    "updateInfo()\0"
};

void ZigbeeModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ZigbeeModule *_t = static_cast<ZigbeeModule *>(_o);
        switch (_id) {
        case 0: _t->broadcast(); break;
        case 1: _t->stops(); break;
        case 2: _t->changePortSetting((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< PortSettings(*)>(_a[3]))); break;
        case 3: _t->updateInfo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ZigbeeModule::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ZigbeeModule::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ZigbeeModule,
      qt_meta_data_ZigbeeModule, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZigbeeModule::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZigbeeModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZigbeeModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZigbeeModule))
        return static_cast<void*>(const_cast< ZigbeeModule*>(this));
    return QThread::qt_metacast(_clname);
}

int ZigbeeModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
