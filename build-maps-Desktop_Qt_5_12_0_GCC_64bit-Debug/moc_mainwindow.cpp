/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../maps/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapOfSattelite_t {
    QByteArrayData data[15];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapOfSattelite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapOfSattelite_t qt_meta_stringdata_MapOfSattelite = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MapOfSattelite"
QT_MOC_LITERAL(1, 15, 9), // "timeInput"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "uint&"
QT_MOC_LITERAL(4, 32, 17), // "timeOfCalculation"
QT_MOC_LITERAL(5, 50, 17), // "on_Update_clicked"
QT_MOC_LITERAL(6, 68, 10), // "getOptions"
QT_MOC_LITERAL(7, 79, 6), // "_delta"
QT_MOC_LITERAL(8, 86, 2), // "_w"
QT_MOC_LITERAL(9, 89, 4), // "_inc"
QT_MOC_LITERAL(10, 94, 3), // "_vi"
QT_MOC_LITERAL(11, 98, 3), // "_hp"
QT_MOC_LITERAL(12, 102, 3), // "_ha"
QT_MOC_LITERAL(13, 106, 18), // "_timeOfCalculation"
QT_MOC_LITERAL(14, 125, 12) // "checkClicked"

    },
    "MapOfSattelite\0timeInput\0\0uint&\0"
    "timeOfCalculation\0on_Update_clicked\0"
    "getOptions\0_delta\0_w\0_inc\0_vi\0_hp\0_ha\0"
    "_timeOfCalculation\0checkClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapOfSattelite[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08 /* Private */,
       6,    8,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Bool,    7,    8,    9,   10,   11,   12,   13,   14,

       0        // eod
};

void MapOfSattelite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapOfSattelite *_t = static_cast<MapOfSattelite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timeInput((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->on_Update_clicked(); break;
        case 2: _t->getOptions((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MapOfSattelite::*)(uint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapOfSattelite::timeInput)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MapOfSattelite::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MapOfSattelite.data,
    qt_meta_data_MapOfSattelite,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MapOfSattelite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapOfSattelite::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapOfSattelite.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MapOfSattelite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MapOfSattelite::timeInput(uint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
