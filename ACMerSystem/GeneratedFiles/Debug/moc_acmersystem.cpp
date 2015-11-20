/****************************************************************************
** Meta object code from reading C++ file 'acmersystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../acmersystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acmersystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ACMerSystem_t {
    QByteArrayData data[7];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ACMerSystem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ACMerSystem_t qt_meta_stringdata_ACMerSystem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ACMerSystem"
QT_MOC_LITERAL(1, 12, 8), // "menuExit"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "menuLogin"
QT_MOC_LITERAL(4, 32, 11), // "menuSetting"
QT_MOC_LITERAL(5, 44, 8), // "startRun"
QT_MOC_LITERAL(6, 53, 8) // "showData"

    },
    "ACMerSystem\0menuExit\0\0menuLogin\0"
    "menuSetting\0startRun\0showData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ACMerSystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ACMerSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ACMerSystem *_t = static_cast<ACMerSystem *>(_o);
        switch (_id) {
        case 0: _t->menuExit(); break;
        case 1: _t->menuLogin(); break;
        case 2: _t->menuSetting(); break;
        case 3: _t->startRun(); break;
        case 4: _t->showData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ACMerSystem::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ACMerSystem.data,
      qt_meta_data_ACMerSystem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ACMerSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ACMerSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ACMerSystem.stringdata))
        return static_cast<void*>(const_cast< ACMerSystem*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ACMerSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
