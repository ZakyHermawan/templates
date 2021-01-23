#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

template <class T> class Pair1 {
private:
  T m_first, m_second;

public:
  Pair1(T a, T b) : m_first{a}, m_second{b} {}

  T first() const { return m_first; }

  T second() const { return m_second; }
};

template <class T1, class T2> class Pair {
private:
  T1 m_first;
  T2 m_second;

public:
  Pair(T1 a, T2 b) : m_first{a}, m_second{b} {}

  T1 first() const { return m_first; }
  T2 second() const { return m_second; }
};

int main() {
  Pair1<int> p1(5, 8);
  cout << "Pair: " << p1.first() << ' ' << p1.second() << endl;

  Pair1<double> p2(2.3, 4.5);
  cout << "Pair: " << p2.first() << ' ' << p2.second() << endl;

  Pair<int, double> dp1(5, 6.7);
  std::cout << "Pair: " << dp1.first() << ' ' << dp1.second() << '\n';

  const Pair<double, int> dp2(2.3, 4);
  std::cout << "Pair: " << dp2.first() << ' ' << dp2.second() << '\n';

  return 0;
}