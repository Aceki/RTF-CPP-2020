#pragma once

namespace Pointers 
{
    template<class T>
    class Counter
    {
    public:
        Counter(T* ptr) : m_pointer(ptr) { }

        Counter(const Counter<T>&) = delete;

        T* pointer() const { return m_pointer; }

        int count() const { return m_count; }

        int increase() { return ++m_count; }
        
        int decrease() { return --m_count; }

        Counter<T>& operator=(const Counter<T>&) = delete;

        ~Counter() { delete m_pointer; }
    private:
        int m_count = 1;
        T* m_pointer = nullptr;
    };
}