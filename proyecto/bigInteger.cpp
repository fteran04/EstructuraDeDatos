#include "bigInteger.h"


void bigInteger::stringToBigInteger(string &cad){
    int i, n = cad.size(), car;
    for(i = cad.size() - 1; i >= 0; i--){
        car = cad[i] - 48;
        vec.push_back(car);
    }
}

string bigInteger::toString(){
    string ans = "", car;
    int i, n = vec.size();
    for(i = 0; i < n; i++){
        car = vec[i] + 48;
        ans = ans + car;
    }
    return ans;
}

bigInteger bigInteger::copyBigInteger(bigInteger &bigInt){
    bigInteger ans;
    string bigString = bigInt.toString();
    int i, n = bigString.size(), car;
    for(i = 0; i < n; i++){
        car = bigString[i] - 48;
        vec.push_back(car);    
    }
    return ans;

}

