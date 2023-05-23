#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class bigInteger{
    private:
    bool sign;
    vector<int> vec;

    public:

    /* Contructoras */
    bigInteger();
    bigInteger( string&);
    bigInteger( bigInteger&);

    /* Modificadoras */
    void add(bigInteger &);
    void product(bigInteger &);
    void substract(bigInteger &);
    void quotient(bigInteger &);
    void remainder(bigInteger &);
    void pow(int);

    /* Analizadoras */
    string toString();
    int get(int);
    int size();
    bool getsign();

    /* Sobrecargas de operadores */
    
    //bigInteger operator+(bigInteger &bigInt);
    //bigInteger operator-(bigInteger &bigInt);
    //bigInteger operator*(bigInteger &bigInt);
    //bigInteger operator/(bigInteger &bigInt);
    //bigInteger operator%(bigInteger &bigInt);
    bool operator==(bigInteger &);
    bool operator<(bigInteger &);
    bool operator<=(bigInteger &);
    

};

#endif
