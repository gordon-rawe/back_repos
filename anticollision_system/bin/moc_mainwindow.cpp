/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Jun 3 12:37:44 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      21,   11,   11,   11, 0x0a,
      33,   11,   11,   11, 0x0a,

 // methods: signature, parameters, type, tag, flags
      53,   11,   47,   11, 0x02,
      68,   11,   64,   11, 0x02,
      83,   11,   47,   11, 0x02,
      98,   11,   47,   11, 0x02,
     120,   11,  112,   11, 0x02,
     130,   11,  112,   11, 0x02,
     145,   11,   64,   11, 0x02,
     165,   11,   47,   11, 0x02,
     186,   11,   64,   11, 0x02,
     204,   11,   64,   11, 0x02,
     219,   11,   64,   11, 0x02,
     229,   11,   64,   11, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0report()\0simulator()\0"
    "goToPage(int)\0float\0getSpeed()\0int\0"
    "getDirection()\0getLongitude()\0"
    "getLatitude()\0QString\0getName()\0"
    "getSafeLevel()\0getNeighbourCount()\0"
    "getNearestDistance()\0getZigbeeSignal()\0"
    "getGpsSignal()\0getSafe()\0getNanoTrackSignal()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->report(); break;
        case 1: _t->simulator(); break;
        case 2: _t->goToPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { float _r = _t->getSpeed();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->getDirection();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { float _r = _t->getLongitude();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 6: { float _r = _t->getLatitude();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->getName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { QString _r = _t->getSafeLevel();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->getNeighbourCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { float _r = _t->getNearestDistance();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->getZigbeeSignal();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { int _r = _t->getGpsSignal();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { int _r = _t->getSafe();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->getNanoTrackSignal();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
