#pragma once

template<class T>
class Counter
{
public:
    Counter(T* ptr) : m_pointer(ptr) { }

    T* pointer() const { return m_pointer; }

    int count() const { return m_count; }

    int increase() { return ++m_count; }
    
    int decrease() { return --m_count; }
private:
    int m_count = 1;
    T* m_pointer = nullptr;
};