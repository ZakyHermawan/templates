#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

template<class T>
class Storage
{
private:
    T m_val;

public:
    Storage(T value) {
        m_val = value;
    }

    void print() {
        cout << m_val << endl;
    }

    ~Storage() = default;
};


template<class T>
class Storage<T*>
{
private:
    T* m_val;

public:

    Storage(T* val) {
        m_val = new T(*val);
    }

    void print() {
        cout << *m_val << endl;
    }

    ~Storage() {
        delete[] m_val;
    }
};

template<>
Storage<char*>::Storage(char* arr) {
    int size = static_cast<int>(strlen(arr)) + 1;
    m_val = new char[size];

    for (int i = 0; i < size; ++i) {
        m_val[i] = arr[i];
    }
}

template<>
void Storage<char*>::print() {
    cout << m_val;
}

template<>
Storage<char*>::~Storage() {
    delete[] m_val;
}

int main() {
    Storage<int> myint(5);
    myint.print();

    int x = 7;
    Storage<int*> myintptr(&x);

    x = 9;
    myintptr.print();

    char* name = new char[40]{ "Alex" };

    Storage< char*> myname(name);

    delete[] name;

    myname.print();
}
