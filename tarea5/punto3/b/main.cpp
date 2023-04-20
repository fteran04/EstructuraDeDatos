#include "lista.h" 
#include <iostream>

int main(){
  Lista l;

  l.insListaOrdenada(100);
  l.insListaOrdenada(2);
  l.insListaOrdenada(3);
  l.insListaOrdenada(4);
  l.insListaOrdenada(1);
  l.insListaOrdenada(1);
  l.insListaOrdenada(10);
  l.insListaOrdenada(9);
  l.insListaOrdenada(5);
  l.insListaOrdenada(14);
  l.insListaOrdenada(18);
  l.insListaOrdenada(2);
  l.insListaOrdenada(0);
  l.insListaOrdenada(-2);
  
  
  //l.insListaOrdenada(-1);
  //l.insListaOrdenada(1111);

  cout << "Los elementos en la lista l son:" << endl;
  for(int i = 1; i <= l.longLista(); i++){
    cout << l.infoLista(i) << " "; 
  }
  cout << endl;

}
