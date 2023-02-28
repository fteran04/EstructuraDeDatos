#include <stdio.h>
char* problemB2(int dx, int dy, int x, int y);
int main(){

char* prueba = problemB2(0,0,1,1);

printf("%s",prueba);

problemB();

return 0;
}

void problemB()
    {
    int dx,dy,x,y,cases;

    scanf("%d", &cases);
    

    while (cases != 0){
        int i;
        scanf("%d", &dx);
        scanf("%d", &dy);

        for (i = 0; i < cases; i++){
        scanf("%d", &x);
        scanf("%d", &y);

        if (x > dx  && y > dy)
    {
        printf("NE\n");
    } 
    else if(x < dx && y > dy){
        printf("NO\n");
    }
    else if (x < dx && y < dy){
        printf("SO\n");
    }
    else if (x > dx && y < dy){
        printf("SE\n");
    }
    else{
        printf("divisa\n");
    }

        }
    scanf("%d", &cases);
    }
     
}


////////////////////////////////////////////////////


char* problemB2(int dx, int dy,int x, int y)
    {

    char* ans;

        if (x > dx  && y > dy)
    {
        ans[0] = 'N';
        ans[1] = 'E';
        ans[2] = '\n';
    } 
    else if(x < dx && y > dy){
        ans[0] = 'N';
        ans[1] = '0';
        ans[2] = '\n';
    }
    else if (x < dx && y < dy){
        ans[0] = 'S';
        ans[1] = 'O';
        ans[2] = '\n';
    }
    else if (x > dx && y < dy){
        ans[0] = 'S';
        ans[1] = 'E';
        ans[2] = '\n';
    }
    else{
        ans[0] = 'd';
        ans[1] = 'i';
        ans[2] = 'v';
        ans[3] = 'i';
        ans[4] = 's';
        ans[5] = 'a';
        ans[6] = '\n';

    }
    return ans;

    }
