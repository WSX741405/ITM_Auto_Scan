/****************************************************************************
** Meta object code from reading C++ file 'IObserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/observer/IObserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IObserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UIObserver_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UIObserver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UIObserver_t qt_meta_stringdata_UIObserver = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UIObserver"
QT_MOC_LITERAL(1, 11, 12), // "UpdateViewer"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 28), // "pcl::PointCloud<PointT>::Ptr"
QT_MOC_LITERAL(4, 54, 10), // "pointCloud"
QT_MOC_LITERAL(5, 65, 16) // "KeepFrameArrived"

    },
    "UIObserver\0UpdateViewer\0\0"
    "pcl::PointCloud<PointT>::Ptr\0pointCloud\0"
    "KeepFrameArrived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIObserver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void UIObserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UIObserver *_t = static_cast<UIObserver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdateViewer((*reinterpret_cast< pcl::PointCloud<PointT>::Ptr(*)>(_a[1]))); break;
        case 1: _t->KeepFrameArrived((*reinterpret_cast< pcl::PointCloud<PointT>::Ptr(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pcl::PointCloud<PointT>::Ptr >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pcl::PointCloud<PointT>::Ptr >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UIObserver::*_t)(pcl::PointCloud<PointT>::Ptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIObserver::UpdateViewer)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UIObserver::*_t)(pcl::PointCloud<PointT>::Ptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIObserver::KeepFrameArrived)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject UIObserver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UIObserver.data,
      qt_meta_data_UIObserver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UIObserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIObserver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UIObserver.stringdata0))
        return static_cast<void*>(const_cast< UIObserver*>(this));
    if (!strcmp(_clname, "IObserver"))
        return static_cast< IObserver*>(const_cast< UIObserver*>(this));
    return QObject::qt_metacast(_clname);
}

int UIObserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void UIObserver::UpdateViewer(pcl::PointCloud<PointT>::Ptr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UIObserver::KeepFrameArrived(pcl::PointCloud<PointT>::Ptr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
