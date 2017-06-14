/****************************************************************************
** Meta object code from reading C++ file 'reader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "reader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_READER_t {
    QByteArrayData data[13];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_READER_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_READER_t qt_meta_stringdata_READER = {
    {
QT_MOC_LITERAL(0, 0, 6), // "READER"
QT_MOC_LITERAL(1, 7, 25), // "on_listWidgetChangedIndex"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "index"
QT_MOC_LITERAL(4, 40, 20), // "on_btnSearch_clicked"
QT_MOC_LITERAL(5, 61, 14), // "on_ContextMenu"
QT_MOC_LITERAL(6, 76, 31), // "on_listWidget_currentRowChanged"
QT_MOC_LITERAL(7, 108, 10), // "currentRow"
QT_MOC_LITERAL(8, 119, 26), // "on_tableBook_doubleClicked"
QT_MOC_LITERAL(9, 146, 7), // "on_Info"
QT_MOC_LITERAL(10, 154, 7), // "on_Edit"
QT_MOC_LITERAL(11, 162, 6), // "on_Del"
QT_MOC_LITERAL(12, 169, 30) // "on_Filter2_currentIndexChanged"

    },
    "READER\0on_listWidgetChangedIndex\0\0"
    "index\0on_btnSearch_clicked\0on_ContextMenu\0"
    "on_listWidget_currentRowChanged\0"
    "currentRow\0on_tableBook_doubleClicked\0"
    "on_Info\0on_Edit\0on_Del\0"
    "on_Filter2_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_READER[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    1,   66,    2, 0x08 /* Private */,
       8,    1,   69,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void READER::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        READER *_t = static_cast<READER *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_listWidgetChangedIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btnSearch_clicked(); break;
        case 2: _t->on_ContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->on_listWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_tableBook_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_Info(); break;
        case 6: _t->on_Edit(); break;
        case 7: _t->on_Del(); break;
        case 8: _t->on_Filter2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject READER::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_READER.data,
      qt_meta_data_READER,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *READER::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *READER::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_READER.stringdata0))
        return static_cast<void*>(const_cast< READER*>(this));
    return QWidget::qt_metacast(_clname);
}

int READER::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
