#include <vector>

class BigInt
{
private:
    std::vector<bool> number;
    unsigned long length = 0;

public:
    BigInt(unsigned long, const std::vector<bool> &);
    BigInt(BigInt &);

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

    BigInt operator+(unsigned long); // TODO: to implement
    BigInt operator-(unsigned long);
    BigInt operator*(unsigned long); // TODO: to implement
    unsigned long operator/(unsigned long);

    BigInt operator+(BigInt); // TODO: to implement
    BigInt operator-(BigInt); 
    BigInt operator*(BigInt); // TODO: to implement
    BigInt operator/(BigInt); // TODO: to implement

    BigInt operator+(BigInt &); // TODO: to implement
    BigInt operator-(BigInt &); // TODO: to implement
    BigInt operator*(BigInt &); // TODO: to implement
    BigInt operator/(BigInt &); // TODO: to implement

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

    void operator+=(BigInt &);
    void operator+=(const BigInt &bigint);

    void BigInt::operator-=(const BigInt &);
    void BigInt::operator-=(const BigInt &);

    BigInt operator%(unsigned long);
    void operator%=(unsigned long);    // TODO: to implement
    unsigned long operator%(BigInt &); // TODO: to implement
    void operator%=(BigInt &);         // TODO: to implement
    BigInt operator%(BigInt);          // TODO: to implement

    std::vector<bool> &bits();
    bool operator[](unsigned long);
    void setBit(unsigned long, bool);
};

template <class Bitset>
unsigned long highestBit(Bitset, unsigned long);