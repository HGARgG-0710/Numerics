#include <algorithm>
#include <stdexcept>
#include <math.h>
#include <bitset>
#include <string>

#include "bigint.hpp"

const std::vector<bool> &null = {0};

BigInt::BigInt(unsigned long length, const std::vector<bool> &number = null)
{
    unsigned long i = 0;

    for (; i < number.size(); i++)
        (*this).number.push_back(number[i]);

    for (i = 0; i < length - number.size(); i++)
        (*this).number.push_back(0);

    (*this).length = (*this).number.size();
};

BigInt::BigInt(const BigInt &original)
{
    (*this).length = original.length;

    for (unsigned long i = 0; i < (*this).length; i++)
        (*this).number.push_back(original.number[i]);
};

void BigInt::flip(unsigned long pos)
{
    (*this).number[pos] = (*this).number[pos] ^ 1;
};

void BigInt::operator+=(unsigned long increase)
{
    for (unsigned long i = 0; i < increase; i++)
        (*this)++;
};

void BigInt::operator-=(unsigned long decrease)
{
    for (unsigned long i = 0; i < decrease; i++)
        (*this)--;
};

BigInt BigInt::operator++(int)
{
    const BigInt copy(*this);

    for (unsigned long i = 0; i < (*this).length; i++)
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

    for (unsigned long i = 0; i < (*this).length; i++)
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

void BigInt::operator>>=(unsigned long shiftSize)
{
    for (unsigned long i = 0; i < (*this).length; i++)
    {
        if (i + shiftSize < (*this).length)
        {
            (*this).number[i] = (*this).number[i + shiftSize];
            continue;
        }

        (*this).number[i] = 0;
    }
}

void BigInt::operator<<=(unsigned long shiftSize)
{
    for (unsigned long i = (*this).length - 1; i > 0; i--)
    {
        if (i - shiftSize >= 0)
        {
            (*this).number[i] = (*this).number[i - shiftSize];
            continue;
        }

        (*this).number[i] = 0;
    }
}

void BigInt::operator*=(unsigned long factor)
{
    const BigInt unit((*this));
    for (unsigned long i = 0; i < factor; i++)
        (*this) += unit;
};

void BigInt::operator/=(unsigned long divisor)
{
    BigInt copy(*this);
    BigInt result((*this).length);

    for (unsigned long i = 0; i < divisor && copy.number != null && copy >= divisor; i++)
    {
        copy -= divisor;
        result++;
    }

    (*this) = result;
};

void BigInt::operator+=(const BigInt &bigint)
{
    for (unsigned long i = 0; i < bigint.length; i++)
        (*this) += bigint.number[i] * (pow(2, i));
};

void BigInt::operator+=(BigInt &bigint)
{
    const BigInt copy(bigint);
    (*this) += copy;
};

bool BigInt::operator==(unsigned long number)
{
    std::bitset<ULONG_MAX> bits;

    for (unsigned long i = 0; i < (*this).length; i++)
        if (bits[i] != (*this).number[i])
            return false;

    return true;
};

bool BigInt::operator==(BigInt &bigint)
{
    if ((*this).length != bigint.length)
        return false;

    for (unsigned long i = 0; i < (*this).length; i++)
        if ((*this).number[i] != bigint.number[i])
            return false;

    return true;
};

bool BigInt::operator>(unsigned long number)
{
    if ((*this) == number)
        return false;

    BigInt comparisonCopy((*this));
    std::bitset<64> bitRepresentation(number);

    long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    long highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        bitRepresentation[highestLongBit] = 0;

        highestBigIntBit = highestBit<std::vector<bool>>(comparisonCopy.number, (*this).length);
        highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());
    }

    return highestBigIntBit > highestLongBit;
};

bool BigInt::operator<(unsigned long number)
{
    if ((*this) == number)
        return false;

    BigInt comparisonCopy((*this));
    std::bitset<64> bitRepresentation(number);

    long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    long highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        bitRepresentation[highestLongBit] = 0;

        highestBigIntBit = highestBit<std::vector<bool>>(comparisonCopy.number, (*this).length);
        highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());
    }

    return highestBigIntBit < highestLongBit;
};

bool BigInt::operator<=(unsigned long number)
{
    if ((*this) == number)
        return true;

    BigInt comparisonCopy((*this));
    std::bitset<64> bitRepresentation(number);

    long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    long highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        bitRepresentation[highestLongBit] = 0;

        highestBigIntBit = highestBit<std::vector<bool>>(comparisonCopy.number, (*this).length);
        highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());
    }

    return highestBigIntBit < highestLongBit;
};

bool BigInt::operator>=(unsigned long number)
{
    if ((*this) == number)
        return true;

    BigInt comparisonCopy((*this));
    std::bitset<64> bitRepresentation(number);

    long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    long highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        bitRepresentation[highestLongBit] = 0;

        highestBigIntBit = highestBit<std::vector<bool>>(comparisonCopy.number, (*this).length);
        highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());
    }

    return highestBigIntBit > highestLongBit;
};


std::vector<bool> &BigInt::bits()
{
    return (*this).number;
};

bool BigInt::operator[](unsigned long pos)
{
    if (pos > (*this).length)
        throw std::out_of_range("The index passed to the BigInt [] operator is too large! Length of your BigInt: " + std::to_string((*this).length) + ", index passed: " + std::to_string(pos) + ".");

    return (*this).number[pos];
};

template <class Bitset>
long highestBit(Bitset bitset, long size)
{
    long highest = size;

    for (; highest > 0; highest--)
        if (bitset[highest])
            break;

    return highest;
};
