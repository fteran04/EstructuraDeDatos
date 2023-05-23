#include "bigInteger.h"

using namespace std;




bigInteger::bigInteger(){}

bigInteger::bigInteger( string &cad){

    int i, num, n = -1;
    bool negative = false;
    if(cad[0] == '-'){
        negative = true;
        n = 0;
    }
    for(i = cad.size()-1 ; i > n; i--){
        num = cad[i] -48;
        vec.push_back(num);
    }
    sign = !negative;
    
}

bigInteger::bigInteger(bigInteger &bigInt){

    sign = bigInt.getsign();
    vec = vector<int>(bigInt.vec);

}

int bigInteger::get(int pos){
    return vec[pos];
}

int bigInteger::size(){
    int n = vec.size();
    return n;
}

bool bigInteger::getsign(){
    return sign;
}

string bigInteger::toString(){
    string ans = "", car;
    int i, n = vec.size();
    if(!sign)
    ans += '-';
    for(i = n-1; i > -1; i--){
        car = vec[i] + 48;
        ans = ans + car;
    }
    return ans;
}

void bigInteger::add(bigInteger &bigInt){
    
    int num, i, acarreo = 0, n = (vec.size() < bigInt.size())?vec.size():bigInt.size();

    for(i = 0; i < n; i++){
        num = vec[i] + bigInt.get(i) + acarreo;
        vec[i] = num % 10;
        acarreo = num / 10;
    }

    if(vec.size() >= bigInt.size()){
        while(i < vec.size() && acarreo != 0){
            num = vec[i] + acarreo;
            vec[i] = num % 10;
            acarreo = num / 10;
            i++;
        }
    }

    else{
        while(i < bigInt.size()){
            num = bigInt.get(i) + acarreo;
            vec.push_back(num % 10);
            acarreo = num / 10;
            i++;
        }
    }

    if(acarreo == 1)
    vec.push_back(1);

}

void bigInteger::substract(bigInteger &bigInt){
    int i, n, j;
    bool provSign;
    if(*this < bigInt){
        provSign = false;
    }
    else{
        provSign = true;
    }
    
    
    if(sign == bigInt.getsign()){
        if(!provSign && !sign || provSign && sign){
            n = bigInt.size();
            for(i = 0; i < n; i++){
                if(vec[i] >= bigInt.get(i))
                vec[i] -= bigInt.get(i);
                else{
                    j = i+1;
                    while(vec[j] == 0){
                        vec[j] = 9;
                        j++;
                    }
                    vec[j] -= 1;
                    vec[i] = vec[i] + 10 - bigInt.get(i);
                    
                }
            }
        }
        else{
            /*Cuando tengo que restarle al del parametro this (this->bigInt.b)*/
        }
    }

    else{
        /*Llamar la suma*/
    }
    sign = provSign;
    while(vec.back() == 0 && vec.size() > 1)
    vec.pop_back();

}

bool bigInteger::operator==(bigInteger &bigInt){
    bool ans = true;
    int i = 0;

    if(vec.size() != bigInt.size())
    ans = false;

    else if(sign != bigInt.getsign())
    ans = false;

    else{
        while(i < vec.size() && ans){
            if(vec[i] != bigInt.get(i))
            ans = false;
            i++;
        }
    }
    return ans;
}

bool bigInteger::operator<(bigInteger &bigInt){

    bool ans;

    if(sign == true && bigInt.getsign() == false){
    ans = false;
    //cout << 1 << endl;
    }

    else if(sign == false && bigInt.getsign() == true){
    ans = true;
    //cout << 2 << endl;
    }

    else if(vec[vec.size()-1] == 0 && bigInt.get(bigInt.size()-1) == 0){
    ans = false;
    //cout << 3 << endl;
    }

    else if(sign && vec.size() > bigInt.size()){
    ans = false;
    //cout << 4 << endl;
    }

    else if(sign && vec.size() < bigInt.size()){
    ans = true;
    //cout << 5 << endl;
    }

    else if(!sign && vec.size() > bigInt.size()){
    ans = true;
    //cout << 6 << endl;
    }

    else if(!sign && vec.size() < bigInt.size()){
    ans = false;
    //cout << 7 << endl;
    }

    else{
        if(sign){
            //cout << 8 << endl;
            int i = vec.size()-1;
            bool flag = true;
            while(i > -1 && flag){
                if(vec[i] != bigInt.get(i))
                flag = false;
                i--;
            }
            i++;
            if(vec[i] < bigInt.get(i))
            ans = true;

            else
            ans = false;
        }
        else{
            //cout << 9 << endl;
            int i = vec.size()-1;
            bool flag = true;
            while(i > -1 && flag){
                if(vec[i] != bigInt.get(i))
                flag = false;
                i--;
            }
            i++;
            if(vec[i] > bigInt.get(i))
            ans = true;

            else
            ans = false;

        }
    }
    return ans;
}

bool bigInteger::operator<=(bigInteger &bigInt){
    bool ans;

    if(sign == true && bigInt.getsign() == false){
    ans = false;
    //cout << 1 << endl;
    }

    else if(sign == false && bigInt.getsign() == true){
    ans = true;
    //cout << 2 << endl;
    }

    else if(vec[vec.size()-1] == 0 && bigInt.get(bigInt.size()-1) == 0){
    ans = true;
    //cout << 3 << endl;
    }

    else if(sign && vec.size() > bigInt.size()){
    ans = false;
    //cout << 4 << endl;
    }

    else if(sign && vec.size() < bigInt.size()){
    ans = true;
    //cout << 5 << endl;
    }

    else if(!sign && vec.size() > bigInt.size()){
    ans = true;
    //cout << 6 << endl;
    }

    else if(!sign && vec.size() < bigInt.size()){
    ans = false;
    //cout << 7 << endl;
    }

    else{
        if(sign){
            //cout << 8 << endl;
            int i = vec.size()-1;
            bool flag = true;
            while(i > -1 && flag){
                if(vec[i] != bigInt.get(i))
                flag = false;
                i--;
            }
            i++;
            if(vec[i] <= bigInt.get(i))
            ans = true;

            else
            ans = false;
        }
        else{
            //cout << 9 << endl;
            int i = vec.size()-1;
            bool flag = true;
            while(i > -1 && flag){
                if(vec[i] != bigInt.get(i))
                flag = false;
                i--;
            }
            i++;
            if(vec[i] >= bigInt.get(i))
            ans = true;

            else
            ans = false;

        }
    }
    return ans;

}
