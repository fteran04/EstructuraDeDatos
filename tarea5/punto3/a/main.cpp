#include "lista.h" 
#include <iostream>
/*Punto 3.a
La comlpejidad de la función tiene un mejor caso y un peor caso, en el mejor caso el tiempo de 
ejecución es O(1) esto sucederia cuando no es necesario recorrer por completo la lista, el valor a
insertar es menor que el el valor más grande de la lista, no seria necesario recorrer por completo
la lista, de igual manera la función insLista tiene un tiempo de ejecucción lienal en su mejor caso
y lineal si es necesario recorrer por completo la lista. Mientras que en el peor caso la complejidad del
algoritmo seria O(n2)*/
void insertarEnListaOrdenada(Lista &l, int v){
  int i = 1, flag = 1;
  while(i <= l.longLista() && flag == 1){
    if(l.infoLista(i) >= v){
      l.insLista(v,i);
      flag = 0;
    }
    i++;
  }
}

int main(){
  Lista l;
  l.anxLista(1);
  l.anxLista(1);
  l.anxLista(2);
  l.anxLista(4);
  l.anxLista(12);
  l.anxLista(12);
  l.anxLista(12);
  l.anxLista(15);

  cout << "Los elementos en la lista l son:" << endl;
  for(int i = 1; i <= l.longLista(); i++){
    cout << l.infoLista(i) << " "; 
  }
  cout << endl;

  insertarEnListaOrdenada(l,3);  

  cout << "Los elementos en la lista l despues de la operacion insertarEnListaOrdenada son:" << endl;
  for(int i = 1; i <= l.longLista(); i++){
    cout << l.infoLista(i) << " "; 
  }
  cout << endl;

}
