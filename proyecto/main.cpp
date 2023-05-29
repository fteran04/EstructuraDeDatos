#include "bigInteger.h"
#include <iostream>

int main(){
    int i = 1, j;
    string a, b;

    string aInt = "";
    string bInt = "";
    string aFloat = "";
    string bFloat = "";

    BigInteger bigInt1, bigInt2, bigFloat1, bigFloat2;

    bool flag;

    while(cin >> a){
        cin >> b;
        j = 0;
        flag = true;

        /* ################ Lectura del BigInteger A ################ */
        /*Parte entera*/
        while(j < a.size() && flag){
            if(a[j] == '.'){
            flag = false;
            }
            else{
            aInt = aInt + a[j];
            }
            j++;
        }
        /*Parte decimal*/
        while(j < a.size()){
            aFloat += a[j];
            j++;
        }

        j = 0;
        flag = true;

        /* ################ Lectura del BigInteger b ################ */
        /*Parte entera*/
        while(j < b.size() && flag){
            if(b[j] == '.')
            flag = false;
            else
            bInt += b[j];
            j++;
        }
        /*Parte decimal*/
        while(j < b.size()){

            bFloat += b[j];
            j++;
        }

        /* Comparar*/
        bigInt1 = BigInteger(aInt);
        bigInt2 = BigInteger(bInt);
        

        if(bigInt1 < bigInt2){
            cout << "Case " << i << ": Smaller" << endl;
        }
        else if(bigInt2 < bigInt1){
            cout << "Case " << i << ": Bigger" << endl;
        }
        else{
            if(aFloat.size() < bFloat.size()){
                while(aFloat.size() != bFloat.size()){
                    aFloat += '0';
                }
            }

            else if(bFloat.size() < aFloat.size()){
                while(aFloat.size() != bFloat.size()){
                    bFloat += '0';
                }
            }
            //cout << "aFloat = " << aFloat << endl << "bFloat = " << bFloat << endl;
            aFloat = '1' + aFloat;
            bFloat = '1' + bFloat;

            bigFloat1 = BigInteger(aFloat);
            bigFloat2 = BigInteger(bFloat);

            if(bigFloat1 < bigFloat2){
            cout << "Case " << i << ": Smaller" << endl;
            }
            else if(bigFloat2 < bigFloat1){
                cout << "Case " << i << ": Bigger" << endl;
            }
            else{
                cout << "Case " << i << ": Same" << endl;
            }
        }

        aInt = "";
        bInt = "";
        aFloat = "";
        bFloat = "";
        a = "";
        b = "";
        i++;
    }
    return 0;
}
