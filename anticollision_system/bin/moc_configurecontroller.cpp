/****************************************************************************
** Meta object code from reading C++ file 'configurecontroller.h'
**
** Created: Fri May 30 14:57:01 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../configurecontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configurecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigureController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      59,   39,   20,   20, 0x05,

 // methods: signature, parameters, type, tag, flags
     123,   20,  110,   20, 0x02,
     140,  138,   20,   20, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_ConfigureController[] = {
    "ConfigureController\0\0onResultChanged()\0"
    "name,target,setting\0"
    "onPortSettingChanged(QString,QString,PortSettings)\0"
    "QVariantList\0getPortNames()\0,\0"
    "setSerialPort(QString,QString)\0"
};

void ConfigureController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConfigureController *_t = static_cast<ConfigureController *>(_o);
        switch (_id) {
        case 0: _t->onResultChanged(); break;
        case 1: _t->onPortSettingChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< PortSettings(*)>(_a[3]))); break;
        case 2: { QVariantList _r = _t->getPortNames();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = _r; }  break;
        case 3: _t->setSerialPort((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConfigureController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConfigureController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ConfigureController,
      qt_meta_data_ConfigureController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfigureController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfigureController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfigureController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigureController))
        return static_cast<void*>(const_cast< ConfigureController*>(this));
    return QObject::qt_metacast(_clname);
}

int ConfigureController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ConfigureController::onResultChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ConfigureController::onPortSettingChanged(QString _t1, QString _t2, PortSettings _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
