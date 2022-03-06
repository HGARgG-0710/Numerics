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

void division_test(const unsigned long size = 12) {
    std::vector<bool> vec11 = {}; 
    std::vector<bool> vec12 = {};

    for (unsigned long i = 0 ; i < size; i ++ ) {
        vec11.push_back(i % 3 == 0 || i % 4 == 0 ? 1 : 0);  
        vec12.push_back(i == (size / 2 - size % 2) ? 1 : 0);   
    }

    BigInt b11(size, vec11);
    BigInt b12(size, vec12);
    BigInt b13 = b11 / b12;

    std::cout << "Division test: \n\n"; 

    b11.output("\n"); 
    b12.output("\n"); 
    b13.output("\n\n\n"); 
} 

int main()
{
    addition_test(14);
    subtraction_test(14);
    division_test(14); 
    return 0;
}
