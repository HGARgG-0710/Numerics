#include <vector>

class BigInt
{
private:
    std::vector<bool> number;
    unsigned long length = 0;

public:
    BigInt(unsigned long, const std::vector<bool> &);
    BigInt(const BigInt &);

    BigInt operator++(int);
    BigInt operator--(int);

    BigInt *operator++();
    BigInt *operator--();

    void operator+=(unsigned long);
    void operator-=(unsigned long);

    void operator*=(unsigned long);
    void operator/=(unsigned long);

    void operator>>=(unsigned long);
    void operator<<=(unsigned long);

    void flip(unsigned long);

    bool operator<(unsigned long);
    bool operator>(unsigned long);
    bool operator>=(unsigned long);
    bool operator<=(unsigned long);

    bool operator<(BigInt &);
    bool operator>(BigInt &);
    bool operator>=(BigInt &);
    bool operator<=(BigInt &);

    bool operator==(unsigned long);
    bool operator==(BigInt &);

    void operator+=(const BigInt &);
    void operator+=(BigInt &);

    unsigned long operator%(unsigned long); // TODO: to implement
    void operator%=(BigInt &);              // TODO: to implement
    void operator%=(const BigInt &);        // TODO: to implement

    std::vector<bool> &bits();
    bool operator[](unsigned long);
    void setBit(unsigned long, bool);
};

template <class Bitset>
unsigned long highestBit(Bitset, unsigned long);