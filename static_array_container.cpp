#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

template <class T, int size> class StaticArray {
private:
  T m_arr[size];

public:
  StaticArray() = default;

  T *getArray();

  T &operator[](int index) { return m_arr[index]; }
};

template <class T, int size> T *StaticArray<T, size>::getArray() {
  return m_arr;
}

int main() {
  StaticArray<int, 12> IntArray;

  for (int i{0}; i < 12; ++i) {
    IntArray[i] = i + 1;
  }

  for (int i = 11; i >= 0; --i) {
    cout << IntArray[i] << ' ';
  }
  cout << endl;

  StaticArray<double, 4> doubleArray;

  for (int count = 0; count < 4; ++count)
    doubleArray[count] = 4.4 + 0.1 * count;

  for (int count = 0; count < 4; ++count)
    cout << doubleArray[count] << ' ';
  cout << endl;

  return 0;
}