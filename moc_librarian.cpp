/****************************************************************************
** Meta object code from reading C++ file 'librarian.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "librarian.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'librarian.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Librarian_t {
    QByteArrayData data[22];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Librarian_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Librarian_t qt_meta_stringdata_Librarian = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Librarian"
QT_MOC_LITERAL(1, 10, 31), // "on_listAction_currentRowChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 10), // "currentRow"
QT_MOC_LITERAL(4, 54, 14), // "on_ContextMenu"
QT_MOC_LITERAL(5, 69, 3), // "pos"
QT_MOC_LITERAL(6, 73, 20), // "on_btnSearch_clicked"
QT_MOC_LITERAL(7, 94, 6), // "on_Add"
QT_MOC_LITERAL(8, 101, 7), // "on_Edit"
QT_MOC_LITERAL(9, 109, 6), // "on_Del"
QT_MOC_LITERAL(10, 116, 15), // "on_ContextMenu2"
QT_MOC_LITERAL(11, 132, 9), // "on_Accept"
QT_MOC_LITERAL(12, 142, 9), // "on_Reject"
QT_MOC_LITERAL(13, 152, 10), // "on_Chitiet"
QT_MOC_LITERAL(14, 163, 7), // "on_Lost"
QT_MOC_LITERAL(15, 171, 33), // "on_FilterMuon_currentIndexCha..."
QT_MOC_LITERAL(16, 205, 5), // "index"
QT_MOC_LITERAL(17, 211, 17), // "on_btnTim_clicked"
QT_MOC_LITERAL(18, 229, 20), // "on_tableMuon_clicked"
QT_MOC_LITERAL(19, 250, 17), // "on_btnPay_clicked"
QT_MOC_LITERAL(20, 268, 24), // "on_btnSearchPhat_clicked"
QT_MOC_LITERAL(21, 293, 18) // "on_btnXuly_clicked"

    },
    "Librarian\0on_listAction_currentRowChanged\0"
    "\0currentRow\0on_ContextMenu\0pos\0"
    "on_btnSearch_clicked\0on_Add\0on_Edit\0"
    "on_Del\0on_ContextMenu2\0on_Accept\0"
    "on_Reject\0on_Chitiet\0on_Lost\0"
    "on_FilterMuon_currentIndexChanged\0"
    "index\0on_btnTim_clicked\0on_tableMuon_clicked\0"
    "on_btnPay_clicked\0on_btnSearchPhat_clicked\0"
    "on_btnXuly_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Librarian[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       4,    1,  102,    2, 0x08 /* Private */,
       6,    0,  105,    2, 0x08 /* Private */,
       7,    0,  106,    2, 0x08 /* Private */,
       8,    0,  107,    2, 0x08 /* Private */,
       9,    0,  108,    2, 0x08 /* Private */,
      10,    1,  109,    2, 0x08 /* Private */,
      11,    0,  112,    2, 0x08 /* Private */,
      12,    0,  113,    2, 0x08 /* Private */,
      13,    0,  114,    2, 0x08 /* Private */,
      14,    0,  115,    2, 0x08 /* Private */,
      15,    1,  116,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    1,  120,    2, 0x08 /* Private */,
      19,    0,  123,    2, 0x08 /* Private */,
      20,    0,  124,    2, 0x08 /* Private */,
      21,    0,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Librarian::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Librarian *_t = static_cast<Librarian *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_listAction_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_ContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->on_btnSearch_clicked(); break;
        case 3: _t->on_Add(); break;
        case 4: _t->on_Edit(); break;
        case 5: _t->on_Del(); break;
        case 6: _t->on_ContextMenu2((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->on_Accept(); break;
        case 8: _t->on_Reject(); break;
        case 9: _t->on_Chitiet(); break;
        case 10: _t->on_Lost(); break;
        case 11: _t->on_FilterMuon_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_btnTim_clicked(); break;
        case 13: _t->on_tableMuon_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->on_btnPay_clicked(); break;
        case 15: _t->on_btnSearchPhat_clicked(); break;
        case 16: _t->on_btnXuly_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Librarian::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Librarian.data,
      qt_meta_data_Librarian,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Librarian::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Librarian::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Librarian.stringdata0))
        return static_cast<void*>(const_cast< Librarian*>(this));
    return QWidget::qt_metacast(_clname);
}

int Librarian::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
