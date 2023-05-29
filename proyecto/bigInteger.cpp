#include "bigInteger.h"

using namespace std;
/*
Operación addLogic
Entrada: Un objeto BigInger al que se le aplica la operación y un BigInteger que se pasa por parametro.
Descripción: La operación sirve como auxiliar en el add y el substract, esta modifica el objeto a que se le aplica, 
            al objeto se le suma el BigInteger que se pasa por parametro indiferentemente del signo (como si de 
            2 numeros positivos se tratara).
*/
void BigInteger::addLogic(BigInteger &bigInt){
    int num, i, acarreo = 0, n = (deq.size() < bigInt.size())?deq.size():bigInt.size();

    for(i = 0; i < n; i++){
        num = deq[i] + bigInt.get(i) + acarreo;
        deq[i] = num % 10;
        acarreo = num / 10;
    }

    if(deq.size() >= bigInt.size()){
        while(i < deq.size() && acarreo != 0){
            num = deq[i] + acarreo;
            deq[i] = num % 10;
            acarreo = num / 10;
            i++;
        }
    }

    else{
        while(i < bigInt.size()){
            num = bigInt.get(i) + acarreo;
            deq.push_back(num % 10);
            acarreo = num / 10;
            i++;
        }
    }

    if(acarreo == 1)
    deq.push_back(1);

}

/*
Operación substractLogic
Entrada: Un objeto BigInger al que se le aplica la operación y un BigInteger que se pasa por parametro.
Descripción: La operación sirve como auxiliar en el add y el substract, esta modifica el objeto a que se le aplica, 
            al objeto se le resta el BigInteger que se pasa por parametro indiferentemente del signo (como si a 
            un numero positivo se le restara otro positivo menor o igual al).
*/
void BigInteger::substractLogic(BigInteger &bigInt){

    int i, j, n = bigInt.size();
    for(i = 0; i < n; i++){
                if(deq[i] >= bigInt.get(i))
                deq[i] -= bigInt.get(i);
                else{
                    j = i+1;
                    while(deq[j] == 0){
                        deq[j] = 9;
                        j++;
                    }
                    deq[j] -= 1;
                    deq[i] = deq[i] + 10 - bigInt.get(i);
                    
                }
            }
    while(deq.back() == 0 && deq.size() > 1)
    deq.pop_back();

}

/*
Operación addCeros
Entrada: Un objeto BigInger al que se le aplica la operación  y un entero positivo.
Descripción: La operación sirve como auxiliar en la multiplicación y el product y agrega ceros al final del BigInteger.
*/
void BigInteger::addCeros(int n){
    int i;
    for(i = 0; i < n; i++){
        deq.push_front(0);
    }
}

/*
Función: get
Entrada: Un BigInteger al que se le aplica la operación y un entero positivo.
Salida: Un número entero positivo entre el 0 y el 9.
Descripción: Al llamar la función sobre un objeto BigInteger se le pasa un entero que correspone a un indice del contenedor
            deque de enteros deq el cual contiene una cifra entre el 0 y el 9 en cada posición, la función devuelve lo cifra
            que se encuentra en la posición solicitada.
*/
int BigInteger::get(int pos){
    return deq[pos];
}

/*
Función: size
Entrada: Un objeto BigInger al que se le aplica la función.
Salida: un entero positivo.
Descripción: La función devuelve el resultado de hacer size() en el contenedor deq, lo que seria el tamaño del BigInteger, es decir
            la cantidad de cifras qu contiene.
*/
int BigInteger::size(){
    int n = deq.size();
    return n;
}

/*
Función: getSign
Entrada: Un objeto BigInger al que se le aplica la función .
Salida: Un booleano.
Descripción: La función devuelve el resultado un booleano correspondiente al signo del BigInteger, true por si es positivo y false 
            por si es negativo.
*/
bool BigInteger::getsign(){
    return sign;
}

/*
Constructor por defecto.
Descripción: Este constructor por defecto solo crea un objeto BigInteger sin haber inicializado el deque con valores ni valor booleano
            para el signo.

*/
BigInteger::BigInteger(){}

/*
Constructor con un cadena.
Entrada: Un objeto BigInger al que se le aplica la función y un string.
Descripción: Este constructor crea un objeto BigInteger inicializando el deque con los valores de la cadena que se pasa por parametro y el signo,
            si hay un menos se inicializa el booleano como false, en caso de no haber un signo se asume que el BigInteger es positivo y el signo
            se inicializa como true.

*/
BigInteger::BigInteger(const string &cad){

    int i, num, n = -1;
    bool negative = false;
    if(cad[0] == '-'){
        negative = true;
        n = 0;
    }
    for(i = cad.size()-1 ; i > n; i--){
        num = cad[i] -48;
        deq.push_back(num);
    }
    sign = !negative;
    
}

/*
Constructor que copia un BigInteger.
Entrada: Un objeto BigInger al que se le aplica el constructor  y un objeto BigInteger que se pasa como parametro.
Descripción: Este constructor crea un objeto BigInteger inicializando el deque y el signo igual al deque del BigInteger que se pasa por parametro.
*/
BigInteger::BigInteger(const BigInteger &bigInt){

    sign = bigInt.sign;
    deq = deque<int>(bigInt.deq);

}

/*
Constructor con un deque<int>.
Entrada: Un objeto BigInger al que se le aplica el constructor y un deque de enteros.
Descripción: Este constructor crea un objeto BigInteger inicializando el deque con los valores del deque que se pasa por parametro y el signo
            por defecto se inicializa en true como si fuera positivo
*/
BigInteger::BigInteger(const deque<int> &d){
    deq = deque<int>(d);
    sign = true;
}

/*
Función: toString
Entrada: Un objeto BigInger al que se le aplica la función.
Salida: Un string.
Descripción: Esta función concatena en un string todos los dijitos contenidos en el BigInteger y si el objeto BigInteger es uno negativo, se 
            coloca al inicio del string el signo "-".

*/
string BigInteger::toString(){
    string ans = "", car;
    int i, n = deq.size();
    if(!sign)
    ans += '-';
    for(i = n-1; i > -1; i--){
        car = deq[i] + 48;
        ans = ans + car;
    }
    return ans;
}

/*
Operación add
Entrada: Un objeto BigInger al que se le aplica la operación y un objeto BigInteger.
Descripción: La operación modifica el objeto a la que se le aplica, si los signos de los BigInteges a operar son iguales se invoca a la operación 
            auxilar addLogic, de lo contrario se llama a substractLogic, el resultado del objeto es el equivalente a haber realizado una suma
            al objeto con el BigInteger pasado por parametro.

*/
void BigInteger::add(BigInteger &bigInt){

    if(sign == bigInt.getsign()){
        this->addLogic(bigInt);
    }
    else{
        bool provSign;
        sign = bigInt.getsign();
        if(sign){
            //cout << 1 << endl;
            if(*this < bigInt){
            provSign = true;
            BigInteger tmp(bigInt);
            tmp.substractLogic(*this);
            deq = deque<int>(tmp.deq);
            }
            else{
            provSign = false;
            this->substractLogic(bigInt);
            }
        }
        else{
            //cout << 2 << endl;
            if(*this < bigInt){
            provSign = true;
            this->substractLogic(bigInt);
            }
            else{
            provSign = false;
            BigInteger tmp(bigInt);
            tmp.substractLogic(*this);
            deq = deque<int>(tmp.deq);
            }
        }
        sign = provSign;
    }
}
/*
Operación substract
Entrada: Un objeto BigInger al que se le aplica la operación y un objeto BigInteger.
Descripción: La operación modifica el objeto a la que se le aplica, si los signos de los BigInteges a operar son iguales se invoca a la operación 
            auxilar substractLogic, de lo contrario se llama a addLogic, el resultado del objeto es el equivalente a haber realizado una resta
            al objeto con el BigInteger pasado por parametro.

*/
void BigInteger::substract(BigInteger &bigInt){

    bool provSign;
    if(*this < bigInt){
        provSign = false;
    }
    else{
        provSign = true;
    }
    
    
    if(sign == bigInt.getsign()){
        if(!provSign && !sign || provSign && sign){
            this->substractLogic(bigInt);
        }
        else{
            BigInteger tmp(*this);
            bigInt.substractLogic(tmp);
            deq = deque<int>(bigInt.deq);
            
        }
    }

    else{
        this->addLogic(bigInt);
    }
    sign = provSign;
    

}

/*
Sobrecarga del operador ==
Entrada: Un objeto BigInger al que se le aplica la sobrecarga y un objeto BigInteger como parametro.
Salida: Un booleano.
Descripción: La sobrecarga del operador permite mediante un booleano determinar si un BigInteger es igual a otro.
*/
bool BigInteger::operator==(BigInteger &bigInt){
    bool ans = true;
    int i = 0;

    if(deq.size() != bigInt.size())
    ans = false;

    else if(sign != bigInt.getsign())
    ans = false;

    else{
        while(i < deq.size() && ans){
            if(deq[i] != bigInt.get(i))
            ans = false;
            i++;
        }
    }
    return ans;
}

/*
Sobrecarga del operador <
Entrada: Un objeto BigInger al que se le aplica la sobrecarga y un objeto BigInteger por parametro.
Salida: Un booleano.
Descripción: La sobrecarga del operador permite mediante un booleano determinar si un BigInteger es menor a otro.
*/
bool BigInteger::operator<(BigInteger &bigInt){

    bool ans;

    if(sign == true && bigInt.getsign() == false){
    ans = false;
    //cout << 1 << endl;
    }

    else if(sign == false && bigInt.getsign() == true){
    ans = true;
    //cout << 2 << endl;
    }

    else if(deq[deq.size()-1] == 0 && bigInt.get(bigInt.size()-1) == 0){
    ans = false;
    //cout << 3 << endl;
    }

    else if(sign && deq.size() > bigInt.size()){
    ans = false;
    //cout << 4 << endl;
    }

    else if(sign && deq.size() < bigInt.size()){
    ans = true;
    //cout << 5 << endl;
    }

    else if(!sign && deq.size() > bigInt.size()){
    ans = true;
    //cout << 6 << endl;
    }

    else if(!sign && deq.size() < bigInt.size()){
    ans = false;
    //cout << 7 << endl;
    }

    else{
        if(sign){
            //cout << 8 << endl;
            int i = deq.size()-1;
            bool flag = true;
            while(i > -1 && flag){
                if(deq[i] != bigInt.get(i))
                flag = false;
                i--;
            }
            i++;
            if(deq[i] < bigInt.get(i))
            ans = true;

            else
            ans = false;
        }
        else{
            //cout << 9 << endl;
            int i = deq.size()-1;
            bool flag = true;
            while(i > -1 && flag){
                if(deq[i] != bigInt.get(i))
                flag = false;
                i--;
            }
            i++;
            if(deq[i] > bigInt.get(i))
            ans = true;

            else
            ans = false;

        }
    }
    return ans;
}

/*
Sobrecarga del operador <=
Entrada: Un objeto BigInger al que se le aplica la sobrecarga y un objeto BigInteger por parametro.
Salida: Un booleano.
Descripción: La sobrecarga del operador permite mediante un booleano determinar si un BigInteger es menor o igual a otro.
*/
bool BigInteger::operator<=(BigInteger &bigInt){
    bool ans;

    if(sign == true && bigInt.getsign() == false){
    ans = false;
    //cout << 1 << endl;
    }

    else if(sign == false && bigInt.getsign() == true){
    ans = true;
    //cout << 2 << endl;
    }

    else if(deq[deq.size()-1] == 0 && bigInt.get(bigInt.size()-1) == 0){
    ans = true;
    //cout << 3 << endl;
    }

    else if(sign && deq.size() > bigInt.size()){
    ans = false;
    //cout << 4 << endl;
    }

    else if(sign && deq.size() < bigInt.size()){
    ans = true;
    //cout << 5 << endl;
    }

    else if(!sign && deq.size() > bigInt.size()){
    ans = true;
    //cout << 6 << endl;
    }

    else if(!sign && deq.size() < bigInt.size()){
    ans = false;
    //cout << 7 << endl;
    }

    else{
        if(sign){
            //cout << 8 << endl;
            int i = deq.size()-1;
            bool flag = true;
            while(i > -1 && flag){
                if(deq[i] != bigInt.get(i))
                flag = false;
                i--;
            }
            i++;
            if(deq[i] <= bigInt.get(i))
            ans = true;

            else
            ans = false;
        }
        else{
            //cout << 9 << endl;
            int i = deq.size()-1;
            bool flag = true;
            while(i > -1 && flag){
                if(deq[i] != bigInt.get(i))
                flag = false;
                i--;
            }
            i++;
            if(deq[i] >= bigInt.get(i))
            ans = true;

            else
            ans = false;

        }
    }
    return ans;

}

/*
Operación product
Entrada: Un objeto BigInger al que se le aplica la operación y un objeto BigInteger como parametro.
Descripción: La operación modifica el objeto, el resultado del obeto es el equivalente a haber realizado una mltiplicación al
            BigInteger por el BigInteger que se pase por parameto.
*/
void BigInteger::product(BigInteger &bigInt){
    //BigInteger aux;
    BigInteger ans("0");
    deque<int> d;
    sign = (sign == bigInt.getsign())?true:false;
    int i, j, num, acarreo = 0;
    for(i = 0; i < bigInt.size(); i++){
        for(j = 0; j < deq.size(); j++){
            num = (bigInt.get(i) * deq[j]) + acarreo;
            d.push_back(num % 10);
            acarreo = num / 10;
        }
        if(acarreo != 0)
        d.push_back(acarreo);
        acarreo = 0;
        BigInteger aux(d);
        aux.addCeros(i);
        ans.add(aux);
        d.clear();
    }
    deq = deque<int>(ans.deq);

    while(deq.back() == 0 && deq.size() > 1){
    deq.pop_back();
    }
}

/*
Operación createTable
Entrada: Un objeto BigInger al que se le aplica la función y un objeto BigInteger como parametro.
Salida: Un vector de BigInteger.
Descripción: La función retorna un vector con 10 elementos,correspondiente a tener la tabla de multiplicar del BigInteger pasado 
            por el parametro de la función del 0 al 9, la funcición sirve como función auxiliar en la operación quotient.
*/
vector<BigInteger> BigInteger::createTable(BigInteger &bigInt){

    int i;
    string num;
    vector<BigInteger> ans;
    for(i = 0; i <= 9; i++){
        num = i + 48;
        BigInteger mult(num);
        BigInteger copyThis(bigInt);
        copyThis.product(mult);
        ans.push_back(copyThis);
    }
    return ans;
}

/*
Función findQuotient
Entrada: Un vector de BigInteger y un objeto BigInteger.
Salida: Un entero positivo entre el 0 y el 9.
Descripción: La función sirve como auxiliar en la operación quotient para encontrar una cifra del cosiente, la función findQuotient
            encuentra un entero con el cual hay que multiplicar el divisor en la operación quotient para hallar una cifra del cosiente,
            para encontrar el entero que se debe retornar se recorre el vector hasta hallar un entero positivo entre 0 y 9 que quepa
            la mayor cantidad de veces en el BigInteger dado en el paramentro.
*/
int BigInteger::findQuotient(vector<BigInteger> &table, BigInteger & bigInt){
    bool flag = true;
    int i = 0;
    string cad;
    while(i < 10 && flag){
        if(table[i] <= bigInt){
            i++;
        }
        else{
            flag = false;
        }
    }
    return i-1;

}

/*
operación quotient
Entrada: Un objeto BigInteger al que se le aplica la operación y otro BigInteger que se pasa por como parametro.
Descripción: La operación modifica el objeto al que se le aplica, el resultado es el equivalente a realizar una división entera al objeto
            con el BigIntger que se pasa por parametro.
*/
void BigInteger::quotient(BigInteger &bigInt){
    BigInteger uno("1");
    if(*this < bigInt){
        //cout << 1 << endl;
        BigInteger cero("0");
        deq = deque<int>(cero.deq);
    }
    
    else if(!(bigInt == uno)){
        //cout << 2 << endl;
        vector<BigInteger> table;
        table = this->createTable(bigInt);
        int i, n = this->size() - bigInt.size();
        string auxString, num;
        for(i = this->size()-1; i >= n; i--){
            num = (this->get(i) + 48) ;
            auxString += num;
        }
        //cout << auxString << endl;
        BigInteger aux(auxString);
        string bigCad = aux.toString();
        //cout << bigCad << endl;

        if(aux < bigInt){
            num = (this->get(i) + 48) ;
            auxString += num;
        }
        else
        i++;
        //cout << auxString << endl;
        aux = BigInteger(auxString);
        int numQuotient;
        string stringAns, car;
        BigInteger bigQuotient("0");
        BigInteger rem("0");
        
        while(i > -1){
            //cout << i << endl;
            numQuotient = findQuotient(table, aux);
            //cout << "aux = " << aux.toString() << endl;
            //cout << "numQuotient = " << numQuotient << endl;
            car = numQuotient + 48;
            stringAns += car;
            bigQuotient = BigInteger(car);
            bigQuotient.product(bigInt);
            rem = BigInteger(aux);
            rem.substract(bigQuotient);
            //cout << "rem = " << rem.toString() << endl;
            if(i > 0){
                //cout << "si" << endl;
                if(rem.toString() == "0"){
                    car = this->get(i-1) + 48;
                    auxString = car;
                }
                else{
                auxString = rem.toString();
                car = this->get(i-1) + 48;
                auxString += car;
                }
                aux = BigInteger(auxString);
            }
            i--;
        }
        BigInteger ans(stringAns);
        deq = deque<int>(ans.deq);
        sign = (sign == bigInt.getsign())?true:false;
    }

    
}

/*
Operación remainder
Entrada: Un objeto BigInteger al que se le aplica la operación y otro BigInteger que se pasa por como parametro.
Descripción: La operación modifica el objeto al que se le aplica, el resultado es el equivalente al residuo al
            realizar una división entera al objeto con el BigIntger que se pasa por parametro.
*/
void BigInteger::remainder(BigInteger &bigInt){
    BigInteger uno("1");
    if(bigInt == *this){
        //cout << "yes" << endl;
        BigInteger cero("0");
        deq = deque<int>(cero.deq);
    }
    else if(*this < bigInt){
        //cout << 1 << endl;
        BigInteger cero("0");
    }

    else if(*this == uno && deq.size() < bigInt.size()){
        //cout << "uno" << endl;
        BigInteger cero("0");
        deq = deque<int>(cero.deq);
    }
    else{
        //cout << 2 << endl;
        vector<BigInteger> table;
        table = this->createTable(bigInt);
        int i, n = this->size() - bigInt.size();
        string auxString, num;
        for(i = this->size()-1; i >= n; i--){
            num = (this->get(i) + 48) ;
            auxString += num;
        }
        BigInteger aux(auxString);
        string bigCad = aux.toString();

        if(aux < bigInt){
            num = (this->get(i) + 48) ;
            auxString += num;
        }
        else
        i++;
        aux = BigInteger(auxString);
        int numQuotient;
        string stringAns, car;
        BigInteger bigQuotient("0");
        BigInteger rem("0");
        
        while(i > -1){
            //cout << "si" << endl;
            numQuotient = findQuotient(table, aux);
            //cout << "numQuotient = " << numQuotient << endl;
            car = numQuotient + 48;
            stringAns += car;
            bigQuotient = BigInteger(car);
            bigQuotient.product(bigInt);
            rem = BigInteger(aux);
            //cout << "rem1 = " << rem.toString() << endl;
            rem.substract(bigQuotient);
            if(i > 0){
                //cout << "si" << endl;
                if(rem.toString() == "0"){
                    car = this->get(i-1) + 48;
                    auxString = car;
                }
                else{
                auxString = rem.toString();
                car = this->get(i-1) + 48;
                auxString += car;
                }
                aux = BigInteger(auxString);
            }
            //cout << "rem2 = " << rem.toString() << endl;
            i--;
        }
        BigInteger ans(stringAns);          
        deq = deque<int>(rem.deq);
        sign = true;
    }

}

/*
Operación pow
Entrada: Un objeto BigInteger al que se le aplica la operación y un entero.
Descripción: La operación modifica el objeto al que se le aplica, el resultado es el equivalente a elevar al
            BigInteger a la n, donde n es un entero que se pasa como parametro de la operación.
*/
void BigInteger::pow(int n){
    int i;
    if(sign == false && n % 2 == 1)
    sign = false;
    else
    sign = true;
    if(n == 0){
        BigInteger uno("1");
        deq = deque<int>(uno.deq);
    }
    else{
        BigInteger aux(*this);
        for(i = 1; i < n; i++){
            this->product(aux);
        }
    }
    

}

/*
Sobrecarga del operador +
Entrada: Un objeto BigInger al que se le aplica la sobrecarga y un objeto BigInteger como parametro.
Salida: Un objeto BigInteger.
Descripción: La sobrecarga del operador realiza la operación de sumar 2 BigInteger y el resultado retornarlo en
            un BigInteger, adicionalmente no modifica ninguno de los objetos.
*/
BigInteger BigInteger::operator+(BigInteger &bigInt){
    BigInteger ans(*this);
    BigInteger aux(bigInt);
    ans.add(aux);
    return ans;
}

/*
Sobrecarga del operador -
Entrada: Un objeto BigInger al que se le aplica la sobrecarga y un objeto BigInteger como parametro.
Salida: Un objeto BigInteger.
Descripción: La sobrecarga del operador realiza la operación de restar 2 BigInteger y el resultado retornarlo en
            un BigInteger, adicionalmente no modifica ninguno de los objetos.
*/
BigInteger BigInteger::operator-(BigInteger &bigInt){
    BigInteger ans(*this);
    BigInteger aux(bigInt);
    ans.substract(aux);
    return ans;
}

/*
Sobrecarga del operador *
Entrada: Un objeto BigInger al que se le aplica la sobrecarga y un objeto BigInteger como parametro.
Salida: Un objeto BigInteger.
Descripción: La sobrecarga del operador realiza la operación de multiplicar 2 BigInteger y el resultado retornarlo en
            un BigInteger adicionalmente no modifica ninguno de los objetos.
*/
BigInteger BigInteger::operator*(BigInteger &bigInt){
    BigInteger ans(*this);
    BigInteger aux(bigInt);
    ans.product(aux);
    return ans;
}

/*
Sobrecarga del operador /
Entrada: Un objeto BigInger al que se le aplica la sobrecarga y un objeto BigInteger como parametro.
Salida: Un objeto BigInteger.
Descripción: La sobrecarga del operador realiza la operación de dividir 2 BigInteger y el resultado retornarlo en
            un BigInteger adicionalmente no modifica ninguno de los objetos.
*/
BigInteger BigInteger::operator/(BigInteger &bigInt){
    BigInteger ans(*this);
    BigInteger aux(bigInt);
    ans.quotient(aux);
    return ans;
}

/*
Sobrecarga del operador %
Entrada: Un objeto BigInger al que se le aplica la sobrecarga y un objeto BigInteger como parametro.
Salida: Un objeto BigInteger.
Descripción: La sobrecarga del operador realiza la operación de hallar el residuo de dividir el objeto BigInteger al que se
            le aplica la sobrecarga con el BigInteger que recibe como parametro de la función.
*/
BigInteger BigInteger::operator%(BigInteger &bigInt){
    BigInteger ans(*this);
    BigInteger aux(bigInt);
    ans.remainder(aux);
    return ans;
}
/*
Función sumarListasValores
Entrada: Una lista de BigInteger.
Salida: Un objeto BigInteger.
Descripción: La función recorre un contenedor list de BigInteger y suma cada uno los BigInitegers de la lista, el resultado
            de la suma se retorna en un BigInteger.
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger> &l){
    BigInteger ans("0");
    list<BigInteger>::iterator it = l.begin();
    for(it = l.begin(); it != l.end(); it++){
        ans.add(*it);
    }
    return ans;
}
/*
Función multiplicarListasValores
Entrada: Una lista de BigInteger.
Salida: Un objeto BigInteger.     
Descripción: La función recorre un contenedor list de BigInteger y multiplica  cada uno los BigInitegers de la lista, el resultado
            de la suma se retorna en un BigInteger.
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger> &l){
    BigInteger ans("1");
    BigInteger cero("0");
    list<BigInteger>::iterator it = l.begin();
    bool flag = true;
    while( it != l.end() & flag){
        BigInteger aux(*it);
        if(aux == cero){
        flag = false;
        }
        ans.product(*it);
        it++;
    }
    if(!flag){
        ans = BigInteger("0");
    }
    return ans;
}
