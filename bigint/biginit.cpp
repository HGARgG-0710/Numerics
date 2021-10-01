#include <algorithm>
#include <math.h>

#include "bigint.hpp"

const std::vector<bool> &null = {0};

BigInt::BigInt(long length, const std::vector<bool> &number = null)
{
    long i = 0;

    for (; i < number.size(); i++)
        (*this).number.push_back(number[i]);

    for (i = 0; i < length - number.size(); i++)
        (*this).number.push_back(0);

    (*this).length = (*this).number.size();
};

BigInt::BigInt(const BigInt &original)
{
    (*this).length = original.length;

    for (long i = 0; i < (*this).length; i++)
        (*this).number.push_back(original.number[i]);
};

void BigInt::flip(long pos)
{
    (*this).number[pos] = (*this).number[pos] ^ 1;
};

void BigInt::operator+=(long increase)
{
    for (long i = 0; i < increase; i++)
        (*this)++;
};

void BigInt::operator-=(long decrease)
{
    for (long i = 0; i < decrease; i++)
        (*this)--;
};

BigInt BigInt::operator++(int)
{
    const BigInt copy(*this);

    for (long i = 0; i < (*this).length; i++)
    {
        if (!(*this).number[i])
        {
            (*this).number[i] = 1;
            break;
        }

        (*this).number[i] = 0;
    }

    return copy;
};

BigInt BigInt::operator--(int)
{
    const BigInt copy(*this);

    for (long i = 0; i < (*this).length; i++)
    {
        if ((*this).number[i])
        {
            (*this).number[i] = 0;
            break;
        }

        (*this).number[i] = 1;
    }

    return copy;
};

void BigInt::operator>>=(long shiftSize)
{
    for (long i = 0; i < (*this).length; i++)
    {
        if (i + shiftSize < (*this).length)
        {
            (*this).number[i] = (*this).number[i + shiftSize];
            continue;
        }

        (*this).number[i] = 0;
    }
}

void BigInt::operator<<=(long shiftSize)
{
    for (long i = (*this).length - 1; i > 0; i--)
    {
        if (i - shiftSize >= 0)
        {
            (*this).number[i] = (*this).number[i - shiftSize];
            continue;
        }

        (*this).number[i] = 0;
    }
}

void BigInt::operator*=(long factor)
{
    const BigInt unit((*this));
    for (long i = 0; i < factor; i++)
        (*this) += unit;
};

void BigInt::operator/=(long divisor)
{
    BigInt copy(*this);
    BigInt result((*this).length);

    for (long i = 0; i < divisor && copy.number != null; i++)
    {
        copy -= divisor;
        result++;
    }

    (*this) = result;
};

void BigInt::operator+=(const BigInt &bigint)
{
    for (long i = 0; i < bigint.length; i++)
        (*this) += bigint.number[i] * (pow(2, i));
};

void BigInt::operator+=(BigInt &bigint)
{
    const BigInt copy(bigint);
    (*this) += copy;
};

bool BigInt::operator==(BigInt &bigint)
{
    if ((*this).length != bigint.length)
        return false;

    for (long i = 0; i < (*this).length; i++)
        if ((*this).number[i] != bigint.number[i])
            return false;

    return true;
};