#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

template <class T> class Storage {
private:
  T m_data;

public:
  Storage(T data) : m_data{data} {}

  void print() { cout << m_data << endl; }

  ~Storage() {}
};

template <> Storage<char *>::Storage(char *data) {
  m_data = new char[strlen(data) + 1];

  for (int i{0}; i < strlen(data); ++i) {
    m_data[i] = data[i];
  }
  m_data[strlen(data)] = 0;
}

template <> Storage<char *>::~Storage() {
  if (m_data != nullptr) {
    delete[] m_data;
  }
  m_data = 0;
}
int main() {
  char *string = new char[40];

  std::cout << "Enter your name: ";
  std::cin.getline(string, 1000);

  Storage<char *> storage(string);

  delete[] string;

  storage.print();
}
