/****************************************************************************
** Meta object code from reading C++ file 'petzval.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "petzval.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'petzval.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Petzval_t {
    QByteArrayData data[17];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Petzval_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Petzval_t qt_meta_stringdata_Petzval = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Petzval"
QT_MOC_LITERAL(1, 8, 6), // "seData"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 3), // "str"
QT_MOC_LITERAL(4, 20, 12), // "loadDatabase"
QT_MOC_LITERAL(5, 33, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(6, 57, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 79, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(8, 103, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(9, 127, 25), // "on_spinBox_5_valueChanged"
QT_MOC_LITERAL(10, 153, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(11, 173, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(12, 195, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(13, 219, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(14, 243, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(15, 277, 25), // "on_spinBox_7_valueChanged"
QT_MOC_LITERAL(16, 303, 23) // "on_pushButton_8_clicked"

    },
    "Petzval\0seData\0\0str\0loadDatabase\0"
    "on_pushButton_3_clicked\0on_pushButton_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "on_spinBox_5_valueChanged\0on_checkBox_clicked\0"
    "on_checkBox_2_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0"
    "on_comboBox_2_currentIndexChanged\0"
    "on_spinBox_7_valueChanged\0"
    "on_pushButton_8_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Petzval[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       4,    0,   87,    2, 0x08 /* Private */,
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void Petzval::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Petzval *_t = static_cast<Petzval *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->loadDatabase(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_5_clicked(); break;
        case 6: _t->on_spinBox_5_valueChanged(); break;
        case 7: _t->on_checkBox_clicked(); break;
        case 8: _t->on_checkBox_2_clicked(); break;
        case 9: _t->on_pushButton_6_clicked(); break;
        case 10: _t->on_pushButton_7_clicked(); break;
        case 11: _t->on_comboBox_2_currentIndexChanged(); break;
        case 12: _t->on_spinBox_7_valueChanged(); break;
        case 13: _t->on_pushButton_8_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Petzval::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Petzval.data,
      qt_meta_data_Petzval,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Petzval::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Petzval::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Petzval.stringdata0))
        return static_cast<void*>(const_cast< Petzval*>(this));
    return QDialog::qt_metacast(_clname);
}

int Petzval::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
