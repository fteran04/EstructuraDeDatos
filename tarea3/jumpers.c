#include<stdio.h>
#include<stdlib.h>

void jumpers(int n, int arr[])
{
    int i;
    int numArr[3000];
    int absArr[3000];  

    for (i = 0; i < n; i++)
    {
        numArr[i] = i +1 ;
    }

    for (i = 0; i < n; i++)
    {
        absArr[i] = abs(arr[i] - arr[i+1]);
    }

    int j = 0;
    
    int flag = 1;

    while (j < n-1 && flag == 1){
        int flag2 = 1;
        int k = 0;
        while(k < n && flag2 == 1){
            if (numArr[j] == absArr[k]){
                flag2 =0;
            }
            k++;
        }
        if (flag2 == 1){
            flag = 0;
        }
        j++;
    }
    if (flag == 1){
        printf("Jolly\n");
    }
    else{
        printf("Not jolly\n");
    }
}

int main()
{   
    int num;
      
    while(scanf("%d", &num) != EOF){
        int a;
        int arreglo[num];
        for (a = 0; a < num; a++){
            scanf("%d", &arreglo[a]);
        }
        jumpers(num,arreglo);
    }

    return 0;
}
    