#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <vector>
#include <string>
#include <algorithm>

#include <stdio.h>

class BigInt{
    public:
        std::vector<char> v;

        BigInt(std::string n_as_string);

        BigInt add(BigInt other);
        BigInt subtract(BigInt other);
        BigInt multiply(BigInt other);
        BigInt divide(BigInt other);

        void print();
};

#endif
