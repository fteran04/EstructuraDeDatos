#include <iostream>
#include "bigInteger.h"


int main(){
    string cad1 = "12345", cad2, cad3;
    bigInteger big1, big2;
    big1.stringToBigInteger(cad1);
    cad2 = big1.toString();

    cout << cad2 << endl;

    big2.copyBigInteger(big1);
    cad3 = big2.toString();
    cout << cad3 << endl;

    cad2 = big1.toString();
    cout << cad2 << endl;

    return 0;
}