#pragma once

#include <algorithm>

namespace Pointers 
{
    template<class T>
    class UniquePointer
    {
    public:
        UniquePointer() = default;

        UniquePointer(T* pointer) : m_pointer(pointer) { }

        UniquePointer(const UniquePointer<T>&) = delete;

        UniquePointer(UniquePointer<T>&&);

        T* get() const { return m_pointer; }

        void reset(T* pointer);

        void swap(UniquePointer<T>&);

        T* release();

        UniquePointer<T>& operator=(const UniquePointer<T>&) = delete;

        UniquePointer<T>& operator=(UniquePointer<T>&&);

        T& operator*() const { return *m_pointer; }

		T* operator->() const { return m_pointer; }

        bool operator==(const UniquePointer<T>& uptr) { return m_pointer == uptr.m_pointer; }

        operator bool() const { return !isEmpty(); }

	~UniquePointer() { delete m_pointer; }
    private:
        bool isEmpty() const { return m_pointer == nullptr; }

        T* m_pointer = nullptr;
    };

    template<class T>
    UniquePointer<T>::UniquePointer(UniquePointer<T>&& uptr)
    {
        m_pointer = uptr.m_pointer;
        uptr.m_pointer = nullptr;
    }

    template<class T>
    void UniquePointer<T>::reset(T* pointer)
    {
        delete m_pointer;

        m_pointer = pointer;
    }

    template<class T>
    void UniquePointer<T>::swap(UniquePointer<T>& uptr) 
    {
        std::swap(m_pointer, uptr.m_pointer);
    }

    template<class T>
    T* UniquePointer<T>::release() 
    {
        T* temp = m_pointer;
        m_pointer = nullptr;
        
        return temp;
    }

    template<class T>
    UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer<T>&& uptr) 
    {
        m_pointer = uptr.m_pointer;
        uptr.m_pointer = nullptr;

        return *this;
    }
}
