#pragma once

class ExampleClass 
{
public:
    ExampleClass(int value) : m_value(value) { }

    int value() const { return m_value; }
private:
    int m_value;
};