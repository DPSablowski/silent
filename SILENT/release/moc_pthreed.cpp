/****************************************************************************
** Meta object code from reading C++ file 'pthreed.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pthreed.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pthreed.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pthreed_t {
    QByteArrayData data[13];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pthreed_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pthreed_t qt_meta_stringdata_pthreed = {
    {
QT_MOC_LITERAL(0, 0, 7), // "pthreed"
QT_MOC_LITERAL(1, 8, 6), // "seData"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 3), // "str"
QT_MOC_LITERAL(4, 20, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 44, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(6, 68, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(7, 92, 22), // "on_checkBox_15_clicked"
QT_MOC_LITERAL(8, 115, 22), // "on_checkBox_16_clicked"
QT_MOC_LITERAL(9, 138, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(10, 162, 16), // "showPointToolTip"
QT_MOC_LITERAL(11, 179, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 192, 5) // "event"

    },
    "pthreed\0seData\0\0str\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "on_checkBox_15_clicked\0on_checkBox_16_clicked\0"
    "on_spinBox_valueChanged\0showPointToolTip\0"
    "QMouseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pthreed[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void pthreed::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pthreed *_t = static_cast<pthreed *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->on_checkBox_15_clicked(); break;
        case 5: _t->on_checkBox_16_clicked(); break;
        case 6: _t->on_spinBox_valueChanged(); break;
        case 7: _t->showPointToolTip((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject pthreed::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_pthreed.data,
      qt_meta_data_pthreed,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pthreed::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pthreed::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pthreed.stringdata0))
        return static_cast<void*>(const_cast< pthreed*>(this));
    return QDialog::qt_metacast(_clname);
}

int pthreed::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE