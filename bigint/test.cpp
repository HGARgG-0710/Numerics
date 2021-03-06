#include <iostream>
#include <vector>

#include "bigint.hpp"

void addition_test(const unsigned long size = 12)
{
    std::vector<bool> vec1 = {};
    std::vector<bool> vec2 = {};

    for (unsigned long i = 0; i < size; i++)
    {
        vec1.push_back(i < size - 1 ? 1 : 0);
        vec2.push_back(i == 0 ? 1 : 0);
    }

    BigInt b1(size, vec1);
    BigInt b2(size, vec2);
    BigInt b3 = b1 + b2;

    std::cout << "Addition test: \n\n";

    b1.output("\n");
    b2.output("\n");
    b3.output("\n\n\n");
}

void subtraction_test(const unsigned long size = 12)
{
    std::vector<bool> vec1 = {};
    std::vector<bool> vec2 = {};

    for (unsigned long i = 0; i < size; i++)
    {
        vec1.push_back(i % 2 == 0 ? 1 : 0);
        vec2.push_back(1);
    }

    BigInt b1(size, vec1);
    BigInt b2(size, vec2);
    BigInt b3 = b2 - b1;

    std::cout << "Subtraction test: \n\n";

    b2.output("\n");
    b1.output("\n");
    b3.output("\n\n\n");
}

void division_test(const unsigned long size = 12)
{
    std::vector<bool> vec1 = {};
    std::vector<bool> vec2 = {};

    for (unsigned long i = 0; i < size; i++)
    {
        vec1.push_back(i % 3 == 0 || i % 4 == 0 ? 1 : 0);
        vec2.push_back(i == (size / 2 - size % 2) ? 1 : 0);
    }

    BigInt b1(size, vec1);
    BigInt b2(size, vec2);
    BigInt b3 = b1 / b2;

    std::cout << "Division test: \n\n";

    b1.output("\n");
    b2.output("\n");
    b3.output("\n\n\n");
}

void modulo_test(unsigned long size = 12)
{
    std::vector<bool> vec1 = {};
    std::vector<bool> vec2 = {};

    for (unsigned long i = 0; i < size; i++)
    {
        vec1.push_back(i % 3 == 0 || i % 4 == 0 ? 1 : 0);
        vec2.push_back(i == (size / 2 - size % 2) ? 1 : 0);
    }

    BigInt b1(size, vec1);
    BigInt b2(size, vec2);
    BigInt b3 = b1 % b2;

    std::cout << "Modulo test: \n\n";

    b1.output("\n");
    b2.output("\n");
    b3.output("\n\n\n");
}

void product_test(unsigned long size = 12)
{
    std::vector<bool> vec1 = {};
    std::vector<bool> vec2 = {};

    for (unsigned long i = 0; i < size; i++)
    {
        vec1.push_back(i % 4 == 0 ? 1 : 0);
        vec2.push_back(i == size - 9 ? 1 : 0);
    }

    BigInt b1(size, vec1);
    BigInt b2(size, vec2);
    BigInt b3 = b1 * b2;

    std::cout << "Multiplication test: \n\n";

    b1.output("\n");
    b2.output("\n");
    b3.output("\n\n\n");
}

int main()
{
    addition_test(14);
    subtraction_test(14);
    product_test();
    division_test(14);
    modulo_test(14);

    return 0;
}
