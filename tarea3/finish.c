
#include<stdio.h>

int finish(int n, int pet[], int dis[]){

    int tank = 0 ,lim = 0,i = 0,meta = n,flgMeta = 0, check = 0, ans;
    while (lim < n*2 && i != meta){
        if ((tank + pet[i] - dis[i] >= 0)){
            if (flgMeta == 0){
                meta = i;
                flgMeta = 1;
            }
            tank += pet[i] - dis[i];
            check += 1;
        }

        else{
            flgMeta = 0;
            tank = 0;
            meta = 0;
            check = 0;
        }
        i = (i+1)%n;
        lim += 1;
    }

    if (check == n && tank >= 0){
        ans = meta +1;
    }
    else{
        ans = -1;
    }

    return ans;

}
int main()
{
    int cases, i, arrPet[100001], arrDis[100001];
    scanf("%d", &cases);
    for (i = 0; i < cases; i++){
        int j, n, ans;
        scanf("%d", &n);

        for (j = 0; j < n; j++){
            scanf("%d", &arrPet[j]);
            }
        for (j = 0; j < n; j++){
            scanf("%d", &arrDis[j]);
        }
            ans = finish(n,arrPet,arrDis);
            if (ans != -1){
            printf("Case %d: Possible from station ", i+1);
            printf("%d\n", ans);
                }
            else{
                printf("Case %d: Not possible\n", i+1);
            }
            

        }
        

    }


