#include <vector>

class BigInt
{
private:
    std::vector<bool> number;
    long length = 0;

public:
    BigInt(long, const std::vector<bool> &);
    BigInt(const BigInt &);

    BigInt operator++(int);
    BigInt operator--(int);

    BigInt *operator++();
    BigInt *operator--();

    void operator+=(long);
    void operator-=(long);

    void operator*=(long);
    void operator/=(long);

    void operator>>=(long);
    void operator<<=(long);

    void flip(long);

    bool operator<(long); // TODO: to implement
    bool operator>(long); // TODO: to implement

    bool operator<(BigInt &); // TODO: to implement
    bool operator>(BigInt &); // TODO: to implement

    bool operator==(long); // TODO: to implement
    bool operator==(BigInt &);

    void operator+=(const BigInt &);
    void operator+=(BigInt &);

    long operator%(long);            // TODO: to implement
    void operator%=(BigInt &);       // TODO: to implement
    void operator%=(const BigInt &); // TODO: to implement
};