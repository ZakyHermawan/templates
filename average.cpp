#include <iostream>

using std::cout;
using std::endl;

class Cents {
private:
  int m_cents;

public:
  Cents(int cents) : m_cents{cents} {}

  friend bool operator>(const Cents &a, const Cents &b) {
    return a.m_cents > b.m_cents;
  }

  friend std::ostream &operator<<(std::ostream &out, const Cents &cents) {
    out << cents.m_cents << " cents" << endl;
    return out;
  }

  Cents operator+=(const Cents &cents) {
    m_cents += cents.m_cents;
    return *this;
  }

  Cents operator/=(int value) {
    m_cents /= value;
    return *this;
  }
};

template <class T> T average(T *array, int length) {
  T sum(0);
  for (int count{0}; count < length; ++count) {
    sum += array[count];
  }

  sum /= length;
  return sum;
}

int main() {
  Cents arr[]{Cents(5), Cents(4), Cents(3)};
  std::cout << average(arr, 3) << std::endl;

  return 0;
}