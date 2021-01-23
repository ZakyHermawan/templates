#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

template<class T, int size>
class StaticArray
{
private:
    T m_arr[size];

public:
    T* getArray() {
        return m_arr;
    }

    void set(int index, T value) {
        m_arr[index] = value;
    }

    T get(int index) {
        return m_arr[index];
    }
};

template<typename T, int size>
void print(StaticArray<T, size>& arr) {
    for (int i{ 0 }; i < size; ++i) {
        cout << arr.get(i) << ' ';
    }
    cout << endl;
}

template<int size>
void print(StaticArray<char, size>& arr) {
    for (int i{ 0 }; i < size; ++i) {
        cout << arr.get(i);
    }
    cout << endl;
}

int main()
{
    StaticArray<char, 14> arr;
    const char* str = "Hello, World!";
    for (int i = 0; i < 14; ++i) {
        arr.set(i, str[i]);
    }

    print(arr);


    return 0;
}
