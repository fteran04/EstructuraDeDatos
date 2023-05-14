#include <iostream>
#include <string>
#include <deque>

using namespace std;

/*
La complejidad computacional del algoritmo que se encarga de resolver el problema es de O(n) donde n es el
la cantidad de caracteres en la cadena cad, la función recorre la cadena caracter por caracter y dependiendo
de si se encuentra con algún simbolo determinado como "[" o "]", en el contenedor ans se van a anexar los caracteres
al inicio o al final de la frase, sin embargo el algoritmo hace un poco más de trabajo ya que cuando se encuentra con
los simbolos "[" o "]" se añaden los caracteres a un deque temporal hasta que se vuelva a encontrar con un simbolo de
home, end o que se acabe la cadena, posterioremente se debe de agregar cada uno de los elementos del deque temporal 
en ans ya sea al inicio o al final de ans, en un ciclo que itera el tamaño del deque temporal.
*/

deque<char> keyboard(string &cad){
    deque<char> ans, tmp;
    int i, j, n = cad.size(), flag;
    for(i = 0; i <= n; i++){
        if(cad[i] == '[' || cad[i] == ']' || i == n){
            if(flag == 0){
                for(j = tmp.size()-1; j > -1; j--){
                    ans.push_front(tmp[j]);
                }
            }
            else {
                for(j = 0; j < tmp.size(); j++){
                    ans.push_back(tmp[j]);   
                } 
            }
            tmp.clear();
        }
        if(i < n){
            if(cad[i] == '['){
                flag = 0;
            }
            else if(cad[i] == ']'){
                flag = 1;
            }
            else{
                tmp.push_back(cad[i]);
            }
        }

    }
    return ans;
}

int main(){
    
    string in;
    deque<char> deq;
    int i;
    
    while(cin >> in){
        deq = keyboard(in);
        for(i = 0; i < deq.size(); i++){
            cout << deq[i];
        }
        cout << endl;
    }       
    return 0;
}