#include "bigInteger.h"
#include <iostream>

using namespace std;


int main(){

    cout << "############### Constructor con string ###############" << endl;
    /*Constructor con string*/
    string a = "-123", b = "1", c = "99", d = "123";
    bigInteger b1(a);
    string bigCad = b1.toString();
    cout << "bigInteger b1 = " << bigCad << endl;
  
    /*Constructor copiando un bigInteger*/
    bigInteger b2(b1);
    string bigCad2 = b2.toString();
    cout << "bigInteger b2 = " << bigCad2 << endl << endl;

    cout << "######################## add ########################" << endl;
    /*add*/
    b1.add(b2);
    bigCad = b1.toString();
    cout << "b1 + b2 = " << bigCad << endl;

    /////////////////////////////////////

    bigInteger b3(b);
    bigInteger b4(c);
    b3.add(b4);
    bigCad2 = b3.toString();
    cout << "b3 + b4 = " << bigCad2 << endl << endl;


    /*Sobrecargas de operadores*/
    cout << "############## Sobrevargas de operadores ##############" << endl;
    /*     ==      */
    bigInteger bs1(a);
    bigInteger bs2(a);
    bigInteger bs3(b);
    bigInteger bs4(d);

    cout << "bs1 = -123" << endl << "bs2 = -123" << endl;
    if(bs1 == bs2)
    cout << "bs1 == bs2 = true" << endl;
    else
    cout << "bs1 == bs2 = false" << endl;

    cout << endl;
    cout << "bs1 = -123" << endl << "bs3 = 1" << endl;
    if(bs1 == bs3)
    cout << "bs1 == bs2 = true" << endl;
    else
    cout << "bs1 == bs2 = false" << endl;
    cout << "----------------------------------------------------" << endl;

    /*     <     */
    cout << endl;
    cout << "bs1 = -123" << endl << "bs4 = 123" << endl;
    if(bs1 < bs4)
    cout << "bs1 < bs4 = true" << endl;
    else
    cout << "bs1 < bs4 = false" << endl;

    cout << endl;
    cout << "bs1 = -123" << endl << "bs3 = 1" << endl;
    if(bs1 < bs3)
    cout << "bs1 < bs3 = true" << endl;
    else
    cout << "bs1 < bs3 = false" << endl;

    cout << endl;
    cout << "bs1 = -123" << endl << "bs2 = -123" << endl;
    if(bs1 < bs2)
    cout << "bs1 < bs2 = true" << endl;
    else
    cout << "bs1 < bs2 = false" << endl;
    cout << "----------------------------------------------------" << endl;

    /*    <=    */

    cout << endl;
    cout << "bs1 = -123" << endl << "bs4 = 123" << endl;
    if(bs1 <= bs4)
    cout << "bs1 <= bs4 = true" << endl;
    else
    cout << "bs1 <= bs4 = false" << endl;

    cout << endl;
    cout << "bs1 = -123" << endl << "bs2 = -123" << endl;
    if(bs1 <= bs2)
    cout << "bs1 <= bs2 = true" << endl;
    else
    cout << "bs1 <= bs2 = false" << endl << endl;

    cout << "###################### substract ######################" << endl;
    string sr1 = "80", sr2 = "40";
    bigInteger br1(sr1);
    bigInteger br2(sr2);

    cout << "br1 = 80" << endl;
    cout << "br2 = 40" << endl;
    br1.substract(br2);
    bigCad = br1.toString();
    cout << "br1 - br2 = " << bigCad << endl;




    return 0;

    


}
