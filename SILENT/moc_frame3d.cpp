/****************************************************************************
** Meta object code from reading C++ file 'frame3d.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "frame3d.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frame3d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Frame3D_t {
    QByteArrayData data[11];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Frame3D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Frame3D_t qt_meta_stringdata_Frame3D = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Frame3D"
QT_MOC_LITERAL(1, 8, 6), // "seData"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 3), // "str"
QT_MOC_LITERAL(4, 20, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 44, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(6, 64, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(7, 86, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(8, 110, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(9, 132, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(10, 156, 25) // "on_spinBox_3_valueChanged"

    },
    "Frame3D\0seData\0\0str\0on_pushButton_2_clicked\0"
    "on_checkBox_clicked\0on_checkBox_2_clicked\0"
    "on_pushButton_3_clicked\0on_checkBox_3_clicked\0"
    "on_pushButton_4_clicked\0"
    "on_spinBox_3_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Frame3D[] = {

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
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Frame3D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Frame3D *_t = static_cast<Frame3D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_checkBox_clicked(); break;
        case 3: _t->on_checkBox_2_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_checkBox_3_clicked(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_spinBox_3_valueChanged(); break;
        default: ;
        }
    }
}

const QMetaObject Frame3D::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Frame3D.data,
      qt_meta_data_Frame3D,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Frame3D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Frame3D::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Frame3D.stringdata0))
        return static_cast<void*>(const_cast< Frame3D*>(this));
    return QDialog::qt_metacast(_clname);
}

int Frame3D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
