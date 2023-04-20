#include "lista.h" 
#include <iostream>


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

  Lista l3;
  l3 = l+l2;

  cout << "Los elementos en la lista l despues concatenar listas son:" << endl;
  for(i = 1; i <= l3.longLista(); i++){
    cout << l3.infoLista(i) << " "; 
  }
  cout << endl;


}
