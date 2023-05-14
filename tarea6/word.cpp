#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
El algoritmo que soluciona el problema se encarga de determinar si es posible armar una palabra del diccionario
dado en el primer bloque de entrada con una las letras dadas en una fila del segundo bloque de entrada, la complejidad
computacional de ese algoritmo es en su peor caso O(n) cuando es necesario recorrer toda la palabra del diccionario
para asegurarse que es posible de armar la palabra con la iformación que se guardo en el mapa, es necesario recorrer
toda la pabra, sin embargo la complejidad en su mejor caso es O(1) esto sucede cuando no es necesario recorrer toda
la cadena ya que se interrumpe el ciclo porque no hay suficientes letras para formar la palabra del diccionario, por 
lo que saber que no es posible armar la palabra se hace en tiempo constante.
*/

int word(string &cad, map<char,int> &m){
    int ans;
    int i = 0;
    bool flag = true;
    while(i < cad.size() && flag){
        map<char,int>::iterator it = m.find(cad[i]);        
        if(it == m.end()){
            flag = false;
        }
        else if(it->second > 0){
            it->second -= 1;
        }
        else{
            flag = false;
        }
        i++;
    }
    if(flag == true){
        ans = 1;
    }
    else{
        ans = 0;
    }
    return ans;


}
int main(){
    vector<string> vec;
    char c;
    string in;
    map<char,int> m,m2;
    cin >> in;
    while(in != "#"){
        vec.push_back(in);
        cin >> in;
        
    }
    cin.ignore();
    getline(cin,in);
    int i, out;
    while(in != "#"){
        out = 0;
        for(i = 0; i < in.size(); i++){
            if(in[i] != ' '){
                m.insert(pair<char,int>(in[i],0));
                m[in[i]] += 1;
            }
        }
        for(i = 0; i < vec.size(); i++){
            m2.clear();
            m2 = m;
            out += word(vec[i], m2);
        }
        cout << out << endl;
        m.clear();
        getline(cin,in);
    }
    return 0;
}