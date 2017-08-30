/****************************************************************************
** Meta object code from reading C++ file 'tsi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SILENT/tsi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tsi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TSI_t {
    QByteArrayData data[10];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TSI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TSI_t qt_meta_stringdata_TSI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "TSI"
QT_MOC_LITERAL(1, 4, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 25), // "on_spinBox_3_valueChanged"
QT_MOC_LITERAL(4, 55, 25), // "on_spinBox_4_valueChanged"
QT_MOC_LITERAL(5, 81, 25), // "on_spinBox_5_valueChanged"
QT_MOC_LITERAL(6, 107, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(7, 131, 25), // "on_spinBox_2_valueChanged"
QT_MOC_LITERAL(8, 157, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(9, 181, 23) // "on_pushButton_4_clicked"

    },
    "TSI\0on_pushButton_2_clicked\0\0"
    "on_spinBox_3_valueChanged\0"
    "on_spinBox_4_valueChanged\0"
    "on_spinBox_5_valueChanged\0"
    "on_spinBox_valueChanged\0"
    "on_spinBox_2_valueChanged\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TSI[] = {

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
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TSI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TSI *_t = static_cast<TSI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->on_spinBox_3_valueChanged(); break;
        case 2: _t->on_spinBox_4_valueChanged(); break;
        case 3: _t->on_spinBox_5_valueChanged(); break;
        case 4: _t->on_spinBox_valueChanged(); break;
        case 5: _t->on_spinBox_2_valueChanged(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TSI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TSI.data,
      qt_meta_data_TSI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TSI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TSI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TSI.stringdata0))
        return static_cast<void*>(const_cast< TSI*>(this));
    return QDialog::qt_metacast(_clname);
}

int TSI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
