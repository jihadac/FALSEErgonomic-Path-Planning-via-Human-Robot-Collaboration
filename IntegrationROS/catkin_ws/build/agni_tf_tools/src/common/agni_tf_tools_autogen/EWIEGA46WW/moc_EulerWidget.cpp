/****************************************************************************
** Meta object code from reading C++ file 'EulerWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/agni_tf_tools/src/common/EulerWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EulerWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EulerWidget_t {
    QByteArrayData data[21];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EulerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EulerWidget_t qt_meta_stringdata_EulerWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "EulerWidget"
QT_MOC_LITERAL(1, 12, 12), // "valueChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "Eigen::Quaterniond"
QT_MOC_LITERAL(4, 45, 1), // "q"
QT_MOC_LITERAL(5, 47, 11), // "axesChanged"
QT_MOC_LITERAL(6, 59, 2), // "a1"
QT_MOC_LITERAL(7, 62, 2), // "a2"
QT_MOC_LITERAL(8, 65, 2), // "a3"
QT_MOC_LITERAL(9, 68, 8), // "setValue"
QT_MOC_LITERAL(10, 77, 14), // "setEulerAngles"
QT_MOC_LITERAL(11, 92, 2), // "e1"
QT_MOC_LITERAL(12, 95, 2), // "e2"
QT_MOC_LITERAL(13, 98, 2), // "e3"
QT_MOC_LITERAL(14, 101, 9), // "normalize"
QT_MOC_LITERAL(15, 111, 12), // "setEulerAxes"
QT_MOC_LITERAL(16, 124, 11), // "axisChanged"
QT_MOC_LITERAL(17, 136, 4), // "axis"
QT_MOC_LITERAL(18, 141, 12), // "angleChanged"
QT_MOC_LITERAL(19, 154, 5), // "angle"
QT_MOC_LITERAL(20, 160, 12) // "updateAngles"

    },
    "EulerWidget\0valueChanged\0\0Eigen::Quaterniond\0"
    "q\0axesChanged\0a1\0a2\0a3\0setValue\0"
    "setEulerAngles\0e1\0e2\0e3\0normalize\0"
    "setEulerAxes\0axisChanged\0axis\0"
    "angleChanged\0angle\0updateAngles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EulerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    3,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   64,    2, 0x0a /* Public */,
      10,    4,   67,    2, 0x0a /* Public */,
      15,    3,   76,    2, 0x0a /* Public */,
      16,    1,   83,    2, 0x09 /* Protected */,
      18,    1,   86,    2, 0x09 /* Protected */,
      20,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    6,    7,    8,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void,

       0        // eod
};

void EulerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EulerWidget *_t = static_cast<EulerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< const Eigen::Quaterniond(*)>(_a[1]))); break;
        case 1: _t->axesChanged((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 2: _t->setValue((*reinterpret_cast< const Eigen::Quaterniond(*)>(_a[1]))); break;
        case 3: _t->setEulerAngles((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 4: _t->setEulerAxes((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 5: _t->axisChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->angleChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->updateAngles(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (EulerWidget::*_t)(const Eigen::Quaterniond & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EulerWidget::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EulerWidget::*_t)(uint , uint , uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EulerWidget::axesChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject EulerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EulerWidget.data,
      qt_meta_data_EulerWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EulerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EulerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EulerWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EulerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void EulerWidget::valueChanged(const Eigen::Quaterniond & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EulerWidget::axesChanged(uint _t1, uint _t2, uint _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
