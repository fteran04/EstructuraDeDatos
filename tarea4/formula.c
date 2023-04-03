/*
Federico Teran Pascuas
8977473
formula.c
*/

/*
El codigo esta dado por dos partes, la lectura de datos en el main() y la funcion formula() que es la encargada
del algoritmo para solucionar el problema. La funcion formula() recibe como parametro una matriz con el orden de 
llegada de los piloto, una arreglo llamado tabla que es donde se va a guardar los puntos obtenidos por cada piloto, 
un arreglo con el sistema de puntaje y adicionalmente recibe el tamaño de los arreglos. El algoritmo consiste en
aplicar el sistema de puntajes a cada una de las columnas de la matriz (cada columna corresponde a las llegadas de
una grand prix) y el resultado es guardado en el arreglo tabla. La complejidad computacional del algoritmo puede
variar dependiento del tamaño de la matriz de llegadas, en un mejor caso la complejidad computacional seria lineal
O(nCols) o O(nFilas) esto sucede cuando la matriz no es cuadrada, por ejemplo, el primer caso de prueba que esta en
el pdf de la tarea tiene una sola fila ya que solo se hace una grand prix y tiene 3 columnas que son 3 pilotos. En el 
peor casola complejidad computacional es cuadratica O(nCols^2) o O(nFilas^2) esto ocurre cuando la matriz de llegadas 
es una matriz cuadrada, como es necesario darle punto a todos los pilotos en todas las grand prix, se tiene que recorrer
la matriz por completo.

*/

#include <stdio.h>
void formula(int arrivals[][500], int *tabla, int nCols, int nFilas, int *score, int nScore){
    int i, j;
    for(i = 0; i < nCols; i++){
        tabla[i] = 0;
    }
    for(i = 0; i < nFilas; i++){
        for(j = 0; j < nCols; j++){
            if(arrivals[i][j] <= nScore){
            tabla[j] += score[arrivals[i][j]-1];
            }
 
        }
    }
    int max= 0, cont = 0;
    for(i = 0; i < nCols; i++){
        if(tabla[i] > max){
            max = tabla[i];
            cont = 1;
        }
        else if(tabla[i] == max){
            cont++;
        }
    }
    
    i = 0;
    while(i < nCols && cont > 0 ){
        if(tabla[i] == max){
            if(cont > 1){
                printf("%d ", i+1);
                cont--;
            }
            else{
                printf("%d", i+1);
                cont--;
            }
        }
        i++;
    }
    printf("\n");
    
}

int main(){
    int arrivals[200][500], tabla[500], score[500], grandPrix, nPilots, nScore, nScore2, i, j; 
    scanf("%d", &grandPrix);
    scanf("%d", &nPilots);
    while(grandPrix != 0 && nPilots != 0){
        for(i = 0; i < grandPrix; i++){
            for(j = 0; j < nPilots; j++){
                scanf("%d", &arrivals[i][j]);
            }
        }
        
        scanf("%d", &nScore);
        for(i = 0 ; i < nScore; i++){
            scanf("%d", &nScore2);
            for(j = 0; j < nScore2; j++){
                scanf("%d", &score[j]);
            }
            formula(arrivals, tabla, nPilots, grandPrix, score, nScore2);
        }
        scanf("%d", &grandPrix);
        scanf("%d", &nPilots);
    }
 
    
    return 0;
}