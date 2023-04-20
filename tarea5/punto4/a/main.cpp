#include "lista.h" 
#include <iostream>

/*Punto 4.a
La complejidad de la función concatenarLIstas va a tener una complejidad O(n^2) donde n es la cantidad
de elementos en l2, al anexar todos los elementos de l2 a l1 se hace necesario recorrer por completo l2
y adicionalmente dentro del ciclo estan anidadas las funciones anxLista y infoLista, donde la función 
anxLista va a tener siempre un tiempo de ejecución lineal*/
void concatenarListas(Lista &l1, Lista &l2){
  int i;
  for(i = 1; i <= l2.longLista(); i++){
    l1.anxLista(l2.infoLista(i));
  }
}

int main(){
  Lista l;
  l.anxLista(1);
  l.anxLista(3);
  l.anxLista(2);
  l.anxLista(4);

  Lista l2;
  l2.anxLista(0);
  l2.anxLista(-1);
  l2.anxLista(9);
  l2.anxLista(0);

  int i;
  cout << "Los elementos en la lista l son:" << endl;
  for(i = 1; i <= l.longLista(); i++){
    cout << l.infoLista(i) << " "; 
  }
  cout << endl;

  cout << "Los elementos en la lista l2 son:" << endl;
  for(i = 1; i <= l2.longLista(); i++){
    cout << l2.infoLista(i) << " "; 
  }
  cout << endl;

  concatenarListas(l,l2);

  cout << "Los elementos en la lista l despues concatenar listas son:" << endl;
  for(i = 1; i <= l.longLista(); i++){
    cout << l.infoLista(i) << " "; 
  }
  cout << endl;


}
