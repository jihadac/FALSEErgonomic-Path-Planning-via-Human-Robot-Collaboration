/****************************************************************************
** Meta object code from reading C++ file 'rotation_property.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/agni_tf_tools/src/plugin/rotation_property.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rotation_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_agni_tf_tools__RotationProperty_t {
    QByteArrayData data[19];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_agni_tf_tools__RotationProperty_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_agni_tf_tools__RotationProperty_t qt_meta_stringdata_agni_tf_tools__RotationProperty = {
    {
QT_MOC_LITERAL(0, 0, 31), // "agni_tf_tools::RotationProperty"
QT_MOC_LITERAL(1, 32, 17), // "quaternionChanged"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 18), // "Eigen::Quaterniond"
QT_MOC_LITERAL(4, 70, 1), // "q"
QT_MOC_LITERAL(5, 72, 12), // "statusUpdate"
QT_MOC_LITERAL(6, 85, 27), // "rviz::StatusProperty::Level"
QT_MOC_LITERAL(7, 113, 13), // "setQuaternion"
QT_MOC_LITERAL(8, 127, 14), // "setEulerAngles"
QT_MOC_LITERAL(9, 142, 9), // "double[3]"
QT_MOC_LITERAL(10, 152, 5), // "euler"
QT_MOC_LITERAL(11, 158, 9), // "normalize"
QT_MOC_LITERAL(12, 168, 2), // "e1"
QT_MOC_LITERAL(13, 171, 2), // "e2"
QT_MOC_LITERAL(14, 174, 2), // "e3"
QT_MOC_LITERAL(15, 177, 12), // "setEulerAxes"
QT_MOC_LITERAL(16, 190, 4), // "axes"
QT_MOC_LITERAL(17, 195, 15), // "updateFromEuler"
QT_MOC_LITERAL(18, 211, 20) // "updateFromQuaternion"

    },
    "agni_tf_tools::RotationProperty\0"
    "quaternionChanged\0\0Eigen::Quaterniond\0"
    "q\0statusUpdate\0rviz::StatusProperty::Level\0"
    "setQuaternion\0setEulerAngles\0double[3]\0"
    "euler\0normalize\0e1\0e2\0e3\0setEulerAxes\0"
    "axes\0updateFromEuler\0updateFromQuaternion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_agni_tf_tools__RotationProperty[] = {

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

void agni_tf_tools::RotationProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RotationProperty *_t = static_cast<RotationProperty *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quaternionChanged((*reinterpret_cast< Eigen::Quaterniond(*)>(_a[1]))); break;
        case 1: _t->statusUpdate((*reinterpret_cast< rviz::StatusProperty::Level(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->setQuaternion((*reinterpret_cast< const Eigen::Quaterniond(*)>(_a[1]))); break;
        case 3: _t->setEulerAngles((*reinterpret_cast< double(*)[3]>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->setEulerAngles((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 5: _t->setEulerAxes((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->updateFromEuler(); break;
        case 7: _t->updateFromQuaternion(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RotationProperty::*_t)(Eigen::Quaterniond );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RotationProperty::quaternionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RotationProperty::*_t)(rviz::StatusProperty::Level , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RotationProperty::statusUpdate)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject agni_tf_tools::RotationProperty::staticMetaObject = {
    { &rviz::StringProperty::staticMetaObject, qt_meta_stringdata_agni_tf_tools__RotationProperty.data,
      qt_meta_data_agni_tf_tools__RotationProperty,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *agni_tf_tools::RotationProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *agni_tf_tools::RotationProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_agni_tf_tools__RotationProperty.stringdata0))
        return static_cast<void*>(this);
    return rviz::StringProperty::qt_metacast(_clname);
}

int agni_tf_tools::RotationProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz::StringProperty::qt_metacall(_c, _id, _a);
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
void agni_tf_tools::RotationProperty::quaternionChanged(Eigen::Quaterniond _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void agni_tf_tools::RotationProperty::statusUpdate(rviz::StatusProperty::Level _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
