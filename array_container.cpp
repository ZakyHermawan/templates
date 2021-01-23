#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

template<class T>
class Array
{
private:
    int m_length{};
    T* m_data{};

public:
    Array(int length) : m_length{ length }
    {
        assert(length > 0);
        m_data = new T[length];
    }

    Array(const Array&) = delete;
    Array& operator= (const Array&) = delete;

    ~Array() {
        erase();
    }

    void erase() {
        if (m_data != nullptr)
            delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    T& operator[] (int index) {
        assert(index >= 0 and index < m_length);
        return m_data[index];
    }

    int getLength() const;
};

template<class T>
int Array<T>::getLength() const {
    return m_length;
}



int main() {
    Array<int> intArray(12);
    Array<double> doubleArray(12);

    for (int count{ 0 }; count < 12; ++count) {
        intArray[count] = count;
        doubleArray[count] = count + 0.5;
    }

    for (int count{ intArray.getLength() - 1 }; count >= 0; --count) {
        cout << intArray[count] << '\t' << doubleArray[count] << endl;
    }

    return 0;
}