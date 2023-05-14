#include <iostream>
#include <map>
#include <deque>

using namespace std;

/*
La complejidad computacional del algoritmo es O(n Log n) donde n es el numero de commands a realizar por caso,
primero se hace llamado a las funciones que crean el deque y el map que son necesarios para resolver el problema,
la complejidad de la función dequeueue() es O(n) donde n es el número menor entre c y p, esto ya que el ciclo itera n
veces y hace solo operaciones de tiempo constante como el push_back(), al mismo tiempo la complejidad de hacer la 
operacíon mapa() es O(n Log n) ya que la función itera en un ciclo de n veces donde n es el número menor entre n y p 
y por cada iteración del ciclo se agrega una clave a un map lo cual se realiza en un tiempo de ejecución O(Log n),
la complejidad de esta 2 funciones se suma a la complejidad total del algoritmo ya que no estan anidadas en ningun ciclo.
Posteriormente se realiza un ciclo que itera las c veces y por cada iteración se hace cin de un carcater, las 
posibilidades de entrada son solo "N" o "E" y en ambos casos se hace llamado de operaciones de complejidad
O(Log n) ya que en ambas situaciones se usa el insert() en un mapa y/o se desea buscar lo que esta guardado en
una dada clave del mapa con la sintaxis de "[]" (map[]). Finalmente al salir del ciclo se hace uso de la operación
clear() en el deque lo que suma a la complejidad un tiempo O(1) y posteriormtente clear() en el mapa lo que suma
a la complejidad total un tiempo O(n).
*/

class nodo{
    public:
    int num;
    int cont;
};

deque<nodo> dequeueue(int n){
    int i;
    deque<nodo> q;
    for(i = 1; i <=n; i++){
        nodo* n = new nodo;
        n->num = i;
        n->cont = 0;
        q.push_back(*n);  
    }
    return q;
}

map<int,int> mapa(int c){
    int i;
    map<int,int> m;
    for(i = 1; i <= c; i++){
        m[i] = 0;
    }
    return m;
}

int main(){
    int c, p, i, num, cont = 1;
    char command;
    cin >> p;
    cin >> c;
    int n = (p < c)?p:c;
    
    map<int,int> m;
    deque<nodo> d;
    
    while(p != 0 && c != 0){
        cout << "Case " << cont << ":" << endl;
        m = mapa(n);
        d = dequeueue(n);
        
        for(i = 0; i < c; i++){
            cin >> command;
            if(command == 'N'){

                while(d.front().cont != m[d.front().num]){
                    d.pop_front();
                }
                
                cout << d.front().num << endl;       
                d.push_back(d.front());
                d.pop_front();
            }
            
            else{
                cin >> num;
                
                m.insert(pair<int,int>(num,0));
                m[num] += 1;
                nodo* n0d0 = new nodo;
                n0d0->num = num;
                n0d0->cont = m[num];
                d.push_front(*n0d0);
            }
        }
        d.clear();
        m.clear();
        cin >> p;
        cin >> c;
        cont++;
        n = (p < c)?p:c;
    }
   
    return 0;
}