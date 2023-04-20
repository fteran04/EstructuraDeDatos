#include "lista.h"


Lista::Lista(){
  act = NULL;
}

/*Punto 4.b
La complejidad computacional al utilizar la sobrecarga del operador + es O(n^2) ya que al hacer l3 = l1 + l2
lo que se esta haciendo por detras es recorrer por completo l1, lo cual seria una complejidad lienal y al mismo,
con el fin de anexar a la lista que se va a retornar (ans), y teniendo en cuenta que la función anxLista tiene
una complejidad computacional O(n) y esta al estar anidada en el ciclo que recorre la lista.*/

Lista Lista::operator+(Lista &l){
  Lista ans;
  Nodo* tmp;
  tmp = act;
  while(tmp != NULL){
    ans.anxLista(tmp->dato);
    tmp = tmp->sig;
  }
  for(int i = 1; i <= l.longLista(); i++){
    ans.anxLista(l.infoLista(i));
  }
  return ans;
  
  

}


void Lista::anxLista(Elemento elem){
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
	tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
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
