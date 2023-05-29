#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>

using namespace std;

class BigInteger{
    private:
    void addLogic(BigInteger &);
    void substractLogic(BigInteger &);
    void addCeros(int);
    vector<BigInteger> createTable(BigInteger & );
    int findQuotient(vector<BigInteger> &, BigInteger &);
    bool sign;
    deque<int> deq;

    public:

    /* Contructoras */
    BigInteger(const string &);
    BigInteger(const BigInteger &);
    BigInteger(const deque<int> &);
    BigInteger();

    /* Modificadoras */
    void add(BigInteger &);
    void product(BigInteger &);
    void substract(BigInteger &);
    void quotient(BigInteger &);
    void remainder(BigInteger &);
    void pow(int);

    /* Analizadoras */
    string toString();
    int get(int);
    int size();
    bool getsign();

    /* Sobrecargas de operadores */
    
    BigInteger operator+(BigInteger &);
    BigInteger operator-(BigInteger &);
    BigInteger operator*(BigInteger &);
    BigInteger operator/(BigInteger &);
    BigInteger operator%(BigInteger &);
    bool operator==(BigInteger &);
    bool operator<(BigInteger &);
    bool operator<=(BigInteger &);

    /* Funciones con listas */
    static BigInteger sumarListaValores(list<BigInteger> &);
    static BigInteger multiplicarListaValores(list<BigInteger> &);
};

#endif
