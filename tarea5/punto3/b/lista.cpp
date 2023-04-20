#include "lista.h"

Lista::Lista(){
  act = NULL;
}

/*Punto 3.b
La complejidad en la función insListaOrdenada varia entre un tiempo de ejecución O(n) y O(1), en su mejor caso en el ciclo
no se hace necesario recorrer por completo la lista, apenas se cumpla que el elemento a insertar se puede ubicar en una 
posición antes de recorrer la lista por completo se puede decir que la complejidad es constante, mientras que en su peor
caso es cuando se hacer necesario tener recorrer toda la lista ya que el elemento a insertar es mayor a todos los demás
por lo que se debe de insertar en la última posición de la lista, en este caso el costo computacional seria lineal
*/
void Lista::insListaOrdenada(Elemento elem){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;
  int flag = 1;

  if(act == NULL){
    nuevo->sig = act;
    act = nuevo;
  }
  else if(nuevo->dato <= act->dato){
    tmp = act;
    nuevo->sig = act;
    act = nuevo;
  }
  else{
    tmp = act;
    while(tmp->sig != NULL && flag == 1){ 
    if(elem >= tmp->dato && elem <= tmp->sig->dato){
      flag = 0;
    }
    else{
    tmp = tmp->sig;
    }
    }
    nuevo->sig = tmp->sig;
    tmp->sig = nuevo;
  }
  
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}
