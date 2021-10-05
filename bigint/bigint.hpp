#include <vector>

const std::vector<bool> null = {0};

class BigInt
{
private:
    std::vector<bool> number;
    unsigned long length = 0;

public:
    BigInt(unsigned long, const std::vector<bool> &);

    // * copy constructors
    BigInt(BigInt &);
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

    BigInt operator+(unsigned long);
    BigInt operator-(unsigned long);
    BigInt operator*(unsigned long);
    unsigned long operator/(unsigned long);

    BigInt operator+(BigInt);
    BigInt operator-(BigInt);
    BigInt operator*(BigInt);
    BigInt operator/(BigInt);

    bool operator<(unsigned long);
    bool operator>(unsigned long);
    bool operator>=(unsigned long);
    bool operator<=(unsigned long);

    // bool operator>=(const BigInt);
    // bool operator<=(const BigInt);
    // bool operator>(const BigInt);
    // bool operator<(const BigInt);

    bool operator<(BigInt);
    bool operator>(BigInt);
    bool operator>=(BigInt);
    bool operator<=(BigInt);

    bool operator==(unsigned long);
    bool operator==(BigInt);
    // bool operator==(const BigInt);

    void operator+=(BigInt);
    // void operator+=(const BigInt);
    void operator-=(BigInt);
    // void operator-=(const BigInt);
    void operator*=(BigInt);
    // void operator*=(const BigInt);
    void operator/=(BigInt);
    // void operator/=(const BigInt);

    BigInt operator%(unsigned long);
    void operator%=(unsigned long);
    void operator%=(BigInt);
    // void operator%=(const BigInt);
    // BigInt operator%(const BigInt);
    BigInt operator%(BigInt);

    std::vector<bool> &bits();
    bool operator[](unsigned long);
    void setBit(unsigned long, bool);
    unsigned long size();
};

template <class Bitset>
unsigned long highestBit(Bitset, unsigned long);