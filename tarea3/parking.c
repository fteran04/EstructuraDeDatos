#include<stdio.h>

int parking(int n, int arr[]){

    int mayor = 0;
    int menor = 100;
    int i;
    int ans;
    for(i = 0; i < n; i++){

        if(arr[i] > mayor){
            mayor = arr[i];
        }

        if(arr[i] < menor){
            menor = arr[i];
        }

    }

   
    ans = (mayor - menor) * 2;


    return ans;
}

int main(){
    int cases, i;
    scanf("%d", &cases);
    for(i = 0; i < cases; i++){
        int locales, j, result;
        int arreglo[100];
        scanf("%d", &locales);
        for(j = 0; j < locales; j++){
            scanf("%d", &arreglo[j]);
        }
        result = parking(locales,arreglo);
        printf("%d\n", result);
    }

}