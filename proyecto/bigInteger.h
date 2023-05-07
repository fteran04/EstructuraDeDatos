#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class bigInteger{
    private:
    vector<int> vec;

    public:

    /* Contructoras */
    void stringToBigInteger(string &cad);
    bigInteger copyBigInteger(bigInteger &bigInt);

    /* Modificadoras */
    void add(bigInteger &bigInt);
    void product(bigInteger &bigInt);
    void substract(bigInteger &bigInt);
    void quotient(bigInteger &bigInt);
    void remainder(bigInteger &bigInt);
    void pow(bigInteger &bigInt);

    /* Analizadoras */
    string toString();

    /* Sobrecargas de operadores */
    bigInteger operator+(const bigInteger &bigInt);
    bigInteger operator-(const bigInteger &bigInt);
    bigInteger operator*(const bigInteger &bigInt);
    bigInteger operator/(const bigInteger &bigInt);
    bigInteger operator%(const bigInteger &bigInt);
    bigInteger operator==(const bigInteger &bigInt);
    bigInteger operator<(const bigInteger &bigInt);
    bigInteger operator<=(const bigInteger &bigInt);

};
#endif

