/*
Federico Teran Pascuas
8977473
dahdahdah.c
*/

/*
La funcion dahdahdah() es un funcion auxiliar que se encarga unicamente de solucionar cada caso, adicionalmente
en el main() se realiza el algoritmo de lectura de datos para el problema, cabe destacar que por cada linea que
es leida y almacenada, en el main() se encarga de dividir la cadena grande en subcadenas que corresponden a una 
unica letra en codigo morse que sera pasada como parametro a la funcion dahdahdah() para ser traducida a una 
letra del abecedario y posteriormente imprimida.

La complejidad computacional de la funcion dahdahdah() cuenta con un mejor caso y un peor caso, en el mejor de los 
escenarios la complejidad del algoritmo seria una complejidad constante, es decir O(1), esto sucede ya la la cadena
de texto cad se compara con cada elemento del vector de cadenas en morse hasta que encuentra con cual coincide y en
ese momento sale del ciclo, en el caso que la cadena cada se encuentra antes de que se recorra todo el vector, se 
se podria decir que el tiempo de ejecucion es costante, mientras que en el peor caso, si se encuentra la cadena en 
la ultima posición del vector, la complejidad del algoritmo seria lineal, esto sucede cuando el caracter que se busca
traducir es el caracter @ que se encuentra en la ultima posicion del vector

*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void dahdahdah(string cad,vector<string> &morse, vector<char> &symbol ){
    int flag = 1;
    int i = 0;
    while(i < 54 && flag == 1)
    {   
        if(cad  == morse[i])
        {
            cout << symbol[i];
            flag = 0;
        }
        i++;
    }

}

int main(){
    string morse[] = {" " , ".-", "-...", "-.-." , "-..", ".", "..-.", "--." , "...." , ".." , ".---" , "-.-" , ".-.." , "--" , "-." , "---" , ".--." ,
                        "--.-" , ".-." , "..." , "-" , "..-", "...-" , ".--" , "-..-" , "-.--" , "--.." , "-----" , ".----" , "..---" , "...--" , "....-" , 
                        "....." , "-...." , "--..." , "---.." , "----." , ".-.-.-" , "--..--" , "..--.." , ".----." , "-.-.--" , "-..-." , "-.--." , "-.--.-", 
                        ".-..." , "---..." , "-.-.-." , "-...-" , ".-.-." , "-....-" , "..--.-" , ".-..-." , ".--.-."};
    vector<string> vecMorse(morse, morse + 54);  

    char symbol[] = {' ' , 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                    '0','1','2','3','4','5','6','7','8','9','.',',','?','\'','!','/','(',')','&',':',';','=','+','-','_', '"' ,'@'};
    vector<char> vecSym(symbol, symbol + 54); 


    int i, flag = 1, j, cases;
    string line;
    string lineMorse;

    cin >> cases;
    cin.ignore();
    for(j = 0; j < cases; j++){
        getline(cin,line);
        cout << "Message #" << j+1 << endl;
        for(i = 0; i < line.size(); i++)
        {
            if(line[i] != ' '){
            if(flag == 1){
                lineMorse = line[i];
                flag = 0;
            }
            else{
                lineMorse = lineMorse + line[i];
            }
        }
        else{
            flag = 1;
            if(i < line.size()-1 && line[i+1] == ' ' ){
                lineMorse = ' ';
                
            }
        }
        if(line[i+1] == ' ' || i == line.size()-1){
            dahdahdah(lineMorse,vecMorse,vecSym);
            flag = 1;
        }
        }   
        cout << endl;  
        if(j < cases -1)
        {
            cout << endl;
        }
    } 
    return 0;
        
}