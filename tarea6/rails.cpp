#include <iostream>
#include <deque>

using namespace std;

/*
El algoritmo que se encarga de solucionar un solo caso, es decir si es posible hacer una combinación determinada
de coches del tren tiene una complejidad computacional de O(n) donde n es el numero de coches del tren. La función en
cada iteración mueve un coche del tren de entrada (1,2,3,...N) hacia la estación y se mueven de tal manera que se intente
formar la combinaicón deseada del tren, si al terminar el ciclo no se pueden organizar los trenes de la forma deseada, 
eso significa que hay coches que quedaron en la estación, finalmente se confirma si quedaron cocches en la estación,
si la cantidad de elementos del deque st (la estación) es igual a 0 entonces si se pudo hacer la combinación deseada, pero si 
por el contrario el tamaño de la estación es mayor que 0, entonces significa que no es posible realizar la combinación 
de coches solicitada.

*/

void rails(int n, deque<int> &d){
    int i;
    deque<int> st;
    deque<int> train;

    for(i = 1; i <= n; i++){
        train.push_back(i);
    }

    for(i = 0; i < d.size(); i++){
        if(st.empty() || st.back() != d[i]){
          if(st.empty()){
            st.push_back(train.front());
            train.pop_front();
          }
            while(st.back() != d[i] && !train.empty() && !st.empty()){
                st.push_back(train.front());
                train.pop_front();
            }
            if(st.back() == d[i]){
                st.pop_back();
            }
        }
        else{
            st.pop_back();
        }
    }
    if(st.empty()){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){

   int n, i, num;
   bool flag;
   deque<int> d;
   cin >> n;
   while(n != 0){
    cin >> num;
    while(num != 0){
        d.push_back(num);
        for(i = 0; i < n-1; i++){
            cin >> num;
            d.push_back(num);
        }
        rails(n,d);
        d.clear();
        cin >> num;
    }   
    cout << endl; 
    cin >> n;
   }
    return 0;
}