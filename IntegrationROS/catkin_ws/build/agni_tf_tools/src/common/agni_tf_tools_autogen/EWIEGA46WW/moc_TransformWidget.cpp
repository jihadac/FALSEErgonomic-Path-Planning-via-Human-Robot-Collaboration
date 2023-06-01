/****************************************************************************
** Meta object code from reading C++ file 'TransformWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/agni_tf_tools/src/common/TransformWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TransformWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TransformWidget_t {
    QByteArrayData data[11];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TransformWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TransformWidget_t qt_meta_stringdata_TransformWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TransformWidget"
QT_MOC_LITERAL(1, 16, 15), // "positionChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "Eigen::Vector3d"
QT_MOC_LITERAL(4, 49, 1), // "p"
QT_MOC_LITERAL(5, 51, 17), // "quaternionChanged"
QT_MOC_LITERAL(6, 69, 18), // "Eigen::Quaterniond"
QT_MOC_LITERAL(7, 88, 1), // "q"
QT_MOC_LITERAL(8, 90, 11), // "setPosition"
QT_MOC_LITERAL(9, 102, 13), // "setQuaternion"
QT_MOC_LITERAL(10, 116, 9) // "changePos"

    },
    "TransformWidget\0positionChanged\0\0"
    "Eigen::Vector3d\0p\0quaternionChanged\0"
    "Eigen::Quaterniond\0q\0setPosition\0"
    "setQuaternion\0changePos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransformWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   45,    2, 0x0a /* Public */,
       9,    1,   48,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void TransformWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TransformWidget *_t = static_cast<TransformWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionChanged((*reinterpret_cast< const Eigen::Vector3d(*)>(_a[1]))); break;
        case 1: _t->quaternionChanged((*reinterpret_cast< const Eigen::Quaterniond(*)>(_a[1]))); break;
        case 2: _t->setPosition((*reinterpret_cast< const Eigen::Vector3d(*)>(_a[1]))); break;
        case 3: _t->setQuaternion((*reinterpret_cast< const Eigen::Quaterniond(*)>(_a[1]))); break;
        case 4: _t->changePos((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TransformWidget::*_t)(const Eigen::Vector3d & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransformWidget::positionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TransformWidget::*_t)(const Eigen::Quaterniond & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransformWidget::quaternionChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TransformWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TransformWidget.data,
      qt_meta_data_TransformWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TransformWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransformWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TransformWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TransformWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TransformWidget::positionChanged(const Eigen::Vector3d & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TransformWidget::quaternionChanged(const Eigen::Quaterniond & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
