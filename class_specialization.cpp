#include <iostream>

using std::cout;
using std::endl;

template<class T>
class Storage8
{
private:
    T m_arr[8]{};

public:
    void set(int index, T value) {
        m_arr[index] = value;
    }

    T get(int index) const {
        return m_arr[index];
    }
};

template<>
class Storage8<bool>
{
private:
    unsigned char m_arr{};

public:
    void set(int index, bool value) {
        int mask{ 1 << index };

        if (value)
            m_arr |= mask;
        else
            m_arr &= ~mask;
    }

    bool get(int index) {

        int mask{ 1 << index };
        return (m_arr & mask);
    }
};


int main()
{
    Storage8<int> intStorage;

    for (int count{ 0 }; count < 8; ++count)
    {
        intStorage.set(count, count);
    }

    for (int count{ 0 }; count < 8; ++count)
    {
        std::cout << intStorage.get(count) << '\n';
    }

    Storage8<bool> boolStorage;

    for (int count{ 0 }; count < 8; ++count)
    {
        boolStorage.set(count, count & 3);
    }

    std::cout << std::boolalpha;

    for (int count{ 0 }; count < 8; ++count)
    {
        std::cout << boolStorage.get(count) << '\n';
    }

    return 0;
}
