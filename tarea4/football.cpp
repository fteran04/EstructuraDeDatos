/*
Federico Teran Pascuas
8977473
footbal.cpp
*/

/*
La solucion para el problema esta conformada por un ensamble de bastantes partes, el codigo esta conformado 
por la definicion de 2 clases, la clase team que corresponde a las estadisticas de un equipo y la clase teams
que contiene a un vector de clases team y además cuenta con funciones internas que pertenecen unicamente a la 
clase teams, funciones como addTeam(), match() y percentage() como cada funcion aporta a la
solucion de cada caso del problema, voy a desarrollar la complejidad de cada una de esta funciones ya que son 
las que aportan a la solucion del problema. Adicionalmente a las 2 clases, en el codigo tambien se desarrollan 
funciones auxiliares, sobrecarga de operadores, sort() y el algoritmo de lectura e impresion de datos en el main().

addTeam():
Ya que esta funcion consiste en agregar un elemento de clase teams a un vector, se puede estimar que la complejidad
de esta funcion es en la mayoria de sus casos constante y en algunas veces lineal, esto porque agregar un elemento 
a un vector tiene un costo computacional O(1), sin embargo como todos los elementos deben de estar contiguos, apenas 
se agote el espacio destinado en la memoria, se tendria que reubicar el vector a un espacio en la memoria donde si
quepan todos los elementos y esten todos seguidos, en ese caso la complejidad seria de un costo lienal.

match()
La funcion match() se encarga de actualizar las estadisticas de 2 equipos, dados sus nombres y los goles hechos en el
partido. La función primero actualiza las estadisticas de un equipo y luego las estadisticas del otro sin embargo el
algoritmo es el mismo. La complejidad de esta funcion tiene mejor y peor caso, ya que para actualizar la informacion 
de un equipo determinado, es necesario que recorra el vector de equipos hasta que el nombre del quipo coincida con el
que es pasado por parametro, en el mejor caso la complejidad computacional es constante, esto ocurre cuando el equipo 
que se desea encontrar no esta en la ultima posicion por lo que no hace falta recorrer todo el vector, mientras que en 
el peor caso la complejidad es lineal, y esto solo sucede cuando el equipo que se desea encontrar esta en la ultima
posicion del vecor.

percentage()
Esta funcion se llama una vez ya se hayan ingresado toda la informacion de los resultados de los encuentros entre 2
equipos y lo que hace la funcion es calcular el porcentaje de puntos adquiridos por el equipo. La complejidad de este
algoritmo es en todos sus casos lienal, porque es necesario recorrer todos el vector de equipos para calcular el 
porcentaje a cada uno de los equipos.


*/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <string>

using namespace std;

class team{
    public:
    string name;
    int position;
    int points;
    int nGames;
    int scoredGoals;
    int sufferedGoals;
    int goalDifference;
    float percentage;

    team(){
        this->name = "";
        this->goalDifference = 0;
        this->nGames = 0;
        this->percentage = 0;
        this->points = 0;
        this->position = 0;
        this->scoredGoals = 0;
        this->sufferedGoals = 0;
    }

    team(string name){
        this->name = name;
        this->goalDifference = 0;
        this->nGames = 0;
        this->percentage = 0;
        this->points = 0;
        this->position = 0;
        this->scoredGoals = 0;
        this->sufferedGoals = 0;
    }   

};

class teams{
    public:
    vector<team> vec;

    void addTeam(team t){
        vec.push_back(t);
    }

    void match(string tA, int pointsA, string tB, int pointsB){
        int i = 0, flag = 1;
        while(i < vec.size() && flag == 1){
            if(tA == (vec[i]).name){
                this->vec[i].nGames += 1;
                this->vec[i].scoredGoals += pointsA;
                this->vec[i].sufferedGoals += pointsB;
                this->vec[i].goalDifference += pointsA - pointsB;
                if(pointsA > pointsB){
                    this->vec[i].points += 3;
                }
                else if(pointsA == pointsB){
                    this->vec[i].points += 1;
                }
                flag = 0;
                
            }
            i++;
        }

        i = 0;
        flag = 1;

        while(i < vec.size() && flag == 1){
            if(tB == (vec[i]).name){
                this->vec[i].nGames += 1;
                this->vec[i].scoredGoals += pointsB;
                this->vec[i].sufferedGoals += pointsA;
                this->vec[i].goalDifference += pointsB - pointsA;
                if(pointsB > pointsA){
                    this->vec[i].points += 3;
                }
                else if(pointsA == pointsB){
                    this->vec[i].points += 1;
                }
                flag = 0;
            }
            i++;
        }

    }

    void percentage(){
        int i;
        float a,b;
        float ans;
        for(i = 0; i < vec.size(); i++){
            if(vec[i].nGames != 0){
                a = vec[i].points * 100;
                b = vec[i].nGames * 3;
                ans = a / b;
                this->vec[i].percentage = ans;
            }
            else{
                this->vec[i].percentage = -1;
            }
        }
    }   
};
bool mayor(team a, team b){
    bool ans;
    int i, car;
    string n1, n2;
    for(i = 0; i < a.name.size(); i++){
        car = a.name[i];
        if(car >= 97 && car <= 122){
            n1 += a.name[i] - 32;
        }
        else{
            n1 += a.name[i];
        }
    }
    for(i = 0; i < b.name.size(); i++){
        car = b.name[i];
        if(car >= 97 && car <= 122){
            n2 += b.name[i] - 32;
        }
        else{
            n2 += b.name[i];
        }
    }
    if(n1 < n2){
        ans = true;
    }
    else if (n1 > n2){
        ans = false;
    }
    return ans;

}

bool operator >(team a, team b){
    bool ans;
    
    if(a.points > b.points){
        ans = true;
    }
    else if(a.points < b.points){
        ans = false;
    }
    
    else if(a.goalDifference > b.goalDifference){
        ans = true;
        }
    else if(a.goalDifference < b.goalDifference){
        ans = false;
        }
   
    else if(a.scoredGoals > b.scoredGoals){
        ans = true;
        }
    else if(a.scoredGoals < b.scoredGoals){
            ans = false;
        }
    else if(mayor(a,b) == true){
        ans = true;
    }
    else{
        ans = false;
    }
    
    return ans;
        
    }

bool comparador(team a, team b){
    bool ans = a > b;
    return ans;
}
int main(){
    teams mundial;
    string name, eq1, eq2,x;
    int eq, par, j, k, p1, p2;
    cin >> eq;
    cin >> par;
    while(eq != 0 && par != 0){
        for(j= 0; j< eq; j++){
            cin >> name;
            mundial.addTeam(team(name));
        }
        for(k = 0; k < par; k++){
            cin >> eq1;
            cin >> p1;
            cin >> x;
            cin >> p2;
            cin >> eq2;

            mundial.match(eq1,p1,eq2,p2);
        }

        mundial.percentage();
        sort(mundial.vec.begin(), mundial.vec.end(), comparador);
        int i, cont = 1, flag = 0;
        for(i = 0; i < mundial.vec.size(); i++){
        if(i == 0){
            const char *name = mundial.vec[i].name.c_str();
           printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", cont, name, mundial.vec[i].points, mundial.vec[i].nGames, mundial.vec[i].scoredGoals, mundial.vec[i].sufferedGoals, mundial.vec[i].goalDifference, mundial.vec[i].percentage);         
        }
        else{
            if(mundial.vec[i].points  != mundial.vec[i-1].points || mundial.vec[i].goalDifference  != mundial.vec[i-1].goalDifference || mundial.vec[i].scoredGoals  != mundial.vec[i-1].scoredGoals || mundial.vec[i].sufferedGoals  != mundial.vec[i-1].sufferedGoals){
                flag = 1;
                cont++;
            }
            else if(mundial.vec[i].points  == mundial.vec[i-1].points && mundial.vec[i].goalDifference  == mundial.vec[i-1].goalDifference && mundial.vec[i].scoredGoals  == mundial.vec[i-1].scoredGoals && mundial.vec[i].sufferedGoals  == mundial.vec[i-1].sufferedGoals){
                flag = 2;
                cont++;
            }
        }
        const char *name = mundial.vec[i].name.c_str();
        if(flag == 1){
            if(mundial.vec[i].percentage != -1){
            printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n",cont, name, mundial.vec[i].points, mundial.vec[i].nGames, mundial.vec[i].scoredGoals, mundial.vec[i].sufferedGoals, mundial.vec[i].goalDifference, mundial.vec[i].percentage);
            }
            else{
                char na[4] = "N/A";
                printf("%2d.%16s%4d%4d%4d%4d%4d%7s\n",cont, name, mundial.vec[i].points, mundial.vec[i].nGames, mundial.vec[i].scoredGoals, mundial.vec[i].sufferedGoals, mundial.vec[i].goalDifference, na);

            }
        }
        if(flag == 2){
            if(mundial.vec[i].percentage != -1){
            printf("%19s%4d%4d%4d%4d%4d%7.2f\n",name, mundial.vec[i].points, mundial.vec[i].nGames, mundial.vec[i].scoredGoals, mundial.vec[i].sufferedGoals, mundial.vec[i].goalDifference, mundial.vec[i].percentage);
            }
            else{
                char na[4] = "N/A";
                printf("%19s%4d%4d%4d%4d%4d%7s\n",name, mundial.vec[i].points, mundial.vec[i].nGames, mundial.vec[i].scoredGoals, mundial.vec[i].sufferedGoals, mundial.vec[i].goalDifference, na);
            }    
        }
    }     
        mundial.vec.clear();
        cin >> eq;
        cin >> par;
        if(eq != 0 && par != 0){
            cout << endl;
        }
    }
    return 0;
}