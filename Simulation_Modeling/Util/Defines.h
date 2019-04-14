#pragma once

#ifndef _DEFINES_H_
#define _DEFINES_H_

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

#define NOTHROW throw()

typedef unsigned char  byte;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

#define SharedPtr boost::shared_ptr
#define WeakPtr   boost::weak_ptr

// Запрещает копирование объекта.
#define DISABLE_COPY(Class) inline Class(const Class&) = delete; Class& operator=(const Class&) = delete;
#define Exception(text) { std::stringstream ss; ss << text; throw std::exception(ss.str().c_str()); }

// Проверяет, является ли объект InstanceType экземпляром класса BaseType.
template<class BaseType, class InstanceType>
inline bool isInstanceOf(InstanceType& instance)
{ return (dynamic_cast< BaseType* >(&instance) != nullptr); }

template<class BaseType, class InstanceType>
inline bool isInstanceOf(InstanceType* instance)
{ return (dynamic_cast< BaseType* >(instance) != nullptr); }

#endif // _DEFINES_H_
