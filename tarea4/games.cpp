/*
Federico Teran Pascuas
8977473
games.cpp
*/

/*
El codigo para solucionar el problema cuenta con una funcion auxiliar solve(), la funcion sort() de la libreria
algorithm y la lectura de datos en main(). La complejidad computacional del algoritmo  encargado desolucionar el
problema se da en la funcion solve() y su complejidad puede variar, en su mejor caso la complejidad es costante,
el algoritmo recorre con un ciclo while la primera cadena que se pasa por parametro (que corresponde a la cadena
menor) y cuando tiene la suficiente informacion para crear una cadena que divida a las 2 cadenas antes de que 
termine de recorrer por completa la primera cadena la bandera se vuelve 0 y se sale del ciclo, mientras que en el
peor caso la complejidad computacional del algoritmo es lineal, esto se da cuando es necesario recorrer la cadena 
por completo para obtener la suficiente informacion necesaria para crear la cadena que en medio de los 2 nombres
que se pasan por parametro.
*/
    
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

void solve(string a, string b){
    char ans[30] = "";
    int flag = 1, i = 0, index = 0;
    char car;
    while(i < a.size() && flag == 1){
      if(i < b.size() - 1){
        if(a[i] == b[i]){
            ans[index] = a[i];
            index++;
        }
        else if(a[i] != b[i] && a[i] != 'Z' && a[i+1] != '\0'){
            car = a[i];
            ans[index] = car + 1;
            index++;
        }
        else if(a[i+1] == '\0'){
            ans[index] = a[i]; 
            index++;
        }
        else if(a[i] == 'Z'){
            ans[index] = 'Z';
            index++;
        }

      }

      else if(i == b.size()-1){
        if(a[i] == b[i] - 1){
            ans[index] = a[i];
            index++; 
        }
        else if(a[i] == b[i]){
            ans[index] = a[i];
            index++;
        }
        else if(a[i] == 'Z'){
            ans[index] = 'Z';
            index++;
        }
        else if(a[i+1] == '\0'){
            ans[index] = a[i];
            index++;

        }
        else{
            car = a[i];
            ans[index] = car + 1;
            index++;
        }
      }
      else{

        if(a[i] == 'Z'){
            ans[index] = 'Z';
            index++;
        }
        else if(a[i+1] == '\0'){
            ans[index] = a[i];
            index++;
        }
        else{
            car = a[i];
            ans[index] = car + 1;
            index++;
        }
      }
      ans[index] = '\0';
      if(ans >= a && b > ans){
            flag = 0;
        }
      i++;
    }
    cout << ans << endl;
}

int main(){
    int n;
    int i;
    string nombres[1001];

    cin >> n;
    while(n != 0){
        for(i = 0; i < n ; i++){
            cin >> nombres[i];
        }
        vector<string> vector(nombres, nombres + n);
        sort(vector.begin(), vector.end());
        string cad1 = vector[n/2-1]; 
        string cad2 = vector[n/2];
        solve(cad1,cad2);
        cin >> n;
    }     
    return 0;
}