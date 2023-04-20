#include "lista.h"
#include <iostream>

/*Punto 1
La complejidad en la función contarOcurrencias es O(n^2) donde n corresponde al tamaño de la lista,
la complejidad es cuadratica porque en el ciclo for se recorre toda la lista hasta al final y
dentro del ciclo for se hace llamado a la función infoLista que tiene una complejidad costante solo
si se desea consultar el valor en un nodo que no sea el ultimo, sin embargo como es necesario reccorer
toda la lista, si se hace el llamado a la función infoLista en su peor caso (linal) que es cuando se llama en la
ultima posición*/

int contarOcurrencias(Lista &l, int v){
  int ans = 0, i;
  for(i = 1; i <= l.longLista(); i++){
    if(v == l.infoLista(i)){
      ans++;
    }
  }
  return ans;
}

/*Punto 2
La complejidad el la función obtenerMenores es O(n^2), esto por que dentro del ciclo for que recorre 
por completo la lista, esta anidada las funciones longLista y al mismo tiempo anxLista las cuales tienen
un teimpo de ejecuón lineal, lo que produciria que el algoritmo tuviera complejidad cuadratica*/

Lista obtenerMenores(Lista &l, int v){
  Lista ans;
  int i, n;
  for(i = 1; i <= l.longLista(); i++){
    n = l.infoLista(i);
    if(n < v){
      ans.anxLista(n);
    }
  }
  return ans;
  
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

  int prueba = contarOcurrencias(l,12);
  Lista lista2  = obtenerMenores(l,10);
  cout << "Los elementos en la lista l son:" << endl;
  for(int i = 1; i <= l.longLista(); i++){
    cout << l.infoLista(i) << " "; 
  }
  cout << endl;
  cout << "Al hacer la operaacion contarOcurrencias con la lista l y el valor 12 es:" << prueba << endl;

  cout << "La lista resultante de aplicar la funcion obtenerMenores a la lista l con el valor 10 es:" << endl;
  for(int j = 1; j <= lista2 .longLista(); j++){
    cout << lista2 .infoLista(j) << " ";
  }
  cout << endl;

}
