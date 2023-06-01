/****************************************************************************
** Meta object code from reading C++ file 'euler_property.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/agni_tf_tools/src/plugin/euler_property.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'euler_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rviz__EulerProperty_t {
    QByteArrayData data[19];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rviz__EulerProperty_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rviz__EulerProperty_t qt_meta_stringdata_rviz__EulerProperty = {
    {
QT_MOC_LITERAL(0, 0, 19), // "rviz::EulerProperty"
QT_MOC_LITERAL(1, 20, 17), // "quaternionChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "Eigen::Quaterniond"
QT_MOC_LITERAL(4, 58, 1), // "q"
QT_MOC_LITERAL(5, 60, 12), // "statusUpdate"
QT_MOC_LITERAL(6, 73, 27), // "rviz::StatusProperty::Level"
QT_MOC_LITERAL(7, 101, 13), // "setQuaternion"
QT_MOC_LITERAL(8, 115, 14), // "setEulerAngles"
QT_MOC_LITERAL(9, 130, 9), // "double[3]"
QT_MOC_LITERAL(10, 140, 5), // "euler"
QT_MOC_LITERAL(11, 146, 9), // "normalize"
QT_MOC_LITERAL(12, 156, 2), // "e1"
QT_MOC_LITERAL(13, 159, 2), // "e2"
QT_MOC_LITERAL(14, 162, 2), // "e3"
QT_MOC_LITERAL(15, 165, 12), // "setEulerAxes"
QT_MOC_LITERAL(16, 178, 9), // "axes_spec"
QT_MOC_LITERAL(17, 188, 18), // "updateFromChildren"
QT_MOC_LITERAL(18, 207, 17) // "emitAboutToChange"

    },
    "rviz::EulerProperty\0quaternionChanged\0"
    "\0Eigen::Quaterniond\0q\0statusUpdate\0"
    "rviz::StatusProperty::Level\0setQuaternion\0"
    "setEulerAngles\0double[3]\0euler\0normalize\0"
    "e1\0e2\0e3\0setEulerAxes\0axes_spec\0"
    "updateFromChildren\0emitAboutToChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rviz__EulerProperty[] = {

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
       7,    1,   64,    2, 0x0a /* Public */,
       8,    2,   67,    2, 0x0a /* Public */,
       8,    4,   72,    2, 0x0a /* Public */,
      15,    1,   81,    2, 0x0a /* Public */,
      17,    0,   84,    2, 0x08 /* Private */,
      18,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   12,   13,   14,   11,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rviz::EulerProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EulerProperty *_t = static_cast<EulerProperty *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quaternionChanged((*reinterpret_cast< Eigen::Quaterniond(*)>(_a[1]))); break;
        case 1: _t->statusUpdate((*reinterpret_cast< rviz::StatusProperty::Level(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->setQuaternion((*reinterpret_cast< const Eigen::Quaterniond(*)>(_a[1]))); break;
        case 3: _t->setEulerAngles((*reinterpret_cast< double(*)[3]>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->setEulerAngles((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 5: _t->setEulerAxes((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->updateFromChildren(); break;
        case 7: _t->emitAboutToChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (EulerProperty::*_t)(Eigen::Quaterniond );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EulerProperty::quaternionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EulerProperty::*_t)(rviz::StatusProperty::Level , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EulerProperty::statusUpdate)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject rviz::EulerProperty::staticMetaObject = {
    { &Property::staticMetaObject, qt_meta_stringdata_rviz__EulerProperty.data,
      qt_meta_data_rviz__EulerProperty,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rviz::EulerProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rviz::EulerProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__EulerProperty.stringdata0))
        return static_cast<void*>(this);
    return Property::qt_metacast(_clname);
}

int rviz::EulerProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Property::qt_metacall(_c, _id, _a);
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
void rviz::EulerProperty::quaternionChanged(Eigen::Quaterniond _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rviz::EulerProperty::statusUpdate(rviz::StatusProperty::Level _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
