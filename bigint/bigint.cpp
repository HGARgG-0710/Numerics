#include <algorithm>
#include <stdexcept>
#include <math.h>
#include <bitset>
#include <string>

#include "bigint.hpp"

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

BigInt::BigInt(BigInt &original)
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
    BigInt copy(*this);

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
    BigInt copy(*this);

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
    BigInt newInt((*this).length + static_cast<unsigned long>(log10(factor)) + 1, (*this).number);

    for (unsigned long i = 0; i < factor; i++)
        newInt += (*this);

    (*this) = newInt;
};

void BigInt::operator/=(unsigned long divisor)
{
    BigInt copy(*this);
    BigInt result((*this).length);

    while (copy.number != null && copy >= divisor)
    {
        copy -= divisor;
        result++;
    }

    (*this) = result;
};

unsigned long BigInt::operator/(unsigned long divisor)
{
    BigInt copy(*this);
    unsigned long result = 0;

    while (copy.number != null && copy >= divisor)
    {
        copy -= divisor;
        result++;
    }

    return result;
};

void BigInt::operator+=(BigInt bigint)
{
    for (unsigned long i = 0; i < bigint.length; i++)
        (*this) += bigint.number[i] * (pow(2, i));
};

void BigInt::operator-=(BigInt bigint)
{
    for (unsigned long i = 0; i < bigint.length; i++)
        (*this) -= bigint.number[i] * (pow(2, i));
};

bool BigInt::operator==(unsigned long number)
{
    std::bitset<ULONG_MAX> bits;

    for (unsigned long i = 0; i < (*this).length; i++)
        if (bits[i] != (*this).number[i])
            return false;

    return true;
};

bool BigInt::operator==(BigInt bigint)
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

    unsigned long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    unsigned long highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        bitRepresentation[highestLongBit] = 0;

        highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
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

    unsigned long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    unsigned long highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        bitRepresentation[highestLongBit] = 0;

        highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
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

    unsigned long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    unsigned long highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        bitRepresentation[highestLongBit] = 0;

        highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
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

    unsigned long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    unsigned long highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        bitRepresentation[highestLongBit] = 0;

        highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
        highestLongBit = highestBit<std::bitset<64>>(bitRepresentation, bitRepresentation.size());
    }

    return highestBigIntBit > highestLongBit;
};

bool BigInt::operator>=(BigInt number)
{
    if ((*this) == number)
        return true;

    BigInt comparisonCopy((*this));
    BigInt anotherCopy((*this));

    unsigned long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    unsigned long highestLongBit = highestBit<BigInt>(anotherCopy, anotherCopy.length);

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        anotherCopy.flip(highestLongBit);

        highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
        highestLongBit = highestBit<BigInt>(anotherCopy, anotherCopy.length);
    }

    return highestBigIntBit > highestLongBit;
};

bool BigInt::operator<=(BigInt number)
{
    if ((*this) == number)
        return true;

    BigInt comparisonCopy((*this));
    BigInt anotherCopy((*this));

    unsigned long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    unsigned long highestLongBit = highestBit<BigInt>(anotherCopy, anotherCopy.length);

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        anotherCopy.flip(highestLongBit);

        highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
        highestLongBit = highestBit<BigInt>(anotherCopy, anotherCopy.length);
    }

    return highestBigIntBit < highestLongBit;
};

bool BigInt::operator<(BigInt number)
{
    if ((*this) == number)
        return false;

    BigInt comparisonCopy((*this));
    BigInt anotherCopy((*this));

    unsigned long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    unsigned long highestLongBit = highestBit<BigInt>(anotherCopy, anotherCopy.length);

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        anotherCopy.flip(highestLongBit);

        highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
        highestLongBit = highestBit<BigInt>(anotherCopy, anotherCopy.length);
    }

    return highestBigIntBit < highestLongBit;
};

bool BigInt::operator>(BigInt number)
{
    if ((*this) == number)
        return false;

    BigInt comparisonCopy((*this));
    BigInt anotherCopy((*this));

    unsigned long highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
    unsigned long highestLongBit = highestBit<BigInt>(anotherCopy, anotherCopy.length);

    while (highestBigIntBit == highestLongBit)
    {
        comparisonCopy.flip(highestBigIntBit);
        anotherCopy.flip(highestLongBit);

        highestBigIntBit = highestBit<BigInt>(comparisonCopy, comparisonCopy.length);
        highestLongBit = highestBit<BigInt>(anotherCopy, anotherCopy.length);
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
        throw std::out_of_range("The index passed to the BigInt::operator[] is too large! Length of your BigInt: " + std::to_string((*this).length) + ", index passed: " + std::to_string(pos) + ".");

    return (*this).number[pos];
};

void BigInt::setBit(unsigned long pos, bool val = 0)
{
    if (pos > (*this).length)
        throw std::out_of_range("The index passed to the BigInt::setBit() method is too large! Length of your BigInt: " + std::to_string((*this).length) + ", index passed: " + std::to_string(pos) + ".");

    (*this).number[pos] = val;
};

BigInt BigInt::operator%(unsigned long number)
{
    BigInt result = (*this) / number;
    return (*this) - result * number;
};

BigInt BigInt::operator-(unsigned long number)
{
    BigInt copy((*this));

    for (unsigned long i = 0; i < number; i++)
        copy--;

    return copy;
};

BigInt BigInt::operator+(unsigned long number)
{
    BigInt copy((*this));
    copy += number;
    return copy;
};

BigInt BigInt::operator-(BigInt bigint)
{
    BigInt copy((*this));
    copy -= bigint;
    return copy;
};

BigInt BigInt::operator+(BigInt bigint)
{
    BigInt copy((*this));
    copy += bigint;
    return copy;
};

BigInt BigInt::operator/(BigInt divisor)
{
    BigInt copy(*this);
    BigInt result((*this).length);

    while (copy.number != null && copy >= divisor)
    {
        copy -= divisor;
        result++;
    }

    return result;
};

void BigInt::operator*=(BigInt factor)
{
    BigInt newInt((*this).length + factor.length + 1, (*this).number);

    for (BigInt i = 0; i < factor.length; i++)
        newInt += (*this);

    (*this) = newInt;
};

BigInt BigInt::operator*(BigInt factor)
{
    BigInt newInt((*this).length + factor.length + 1, (*this).number);

    for (unsigned long i = 0; i < factor.length; i++)
        newInt += (*this);

    return newInt;
};

BigInt BigInt::operator*(unsigned long factor)
{
    BigInt newInt((*this).length + static_cast<unsigned long>(log10(factor)) + 1, (*this).number);

    for (unsigned long i = 0; i < factor; i++)
        newInt += (*this);

    return newInt;
};

void BigInt::operator/=(BigInt divisor)
{
    BigInt copy(*this);
    BigInt result((*this).length);

    while (copy.number != null && copy >= divisor)
    {
        copy -= divisor;
        result++;
    }

    (*this) = result;
};

unsigned long BigInt::size()
{
    return (*this).length;
};

void BigInt::operator%=(unsigned long divisor)
{
    BigInt divided = (*this) / divisor;
    (*this) -= divided * divisor;
};

BigInt BigInt::operator%(BigInt bigint)
{
    BigInt divided = (*this) / bigint;
    return (*this) - divided * bigint;
};

void BigInt::operator%=(BigInt divisor)
{
    BigInt divided = (*this) / divisor;
    (*this) -= divided * divisor;
};

template <class Bitset>
unsigned long highestBit(Bitset bitset, unsigned long size)
{
    unsigned long highest = size;

    for (; highest > 0; highest--)
        if (bitset[highest])
            break;

    return highest;
};
