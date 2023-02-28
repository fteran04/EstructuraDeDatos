#include<stdio.h>
int lock(int a, int b, int c, int d)
{
    int ans = 0;
    // 1.
    ans += 40*2;
    //2.
    ans += ((40-b)+a) % 40;
    //3.
    ans += 40;
    //4.        
    ans += ((40-b)+c) % 40;
    //5.
    ans += (((40-d)+c) %40);
    printf("%d\n", ans*9);

}
int main()
{
    int aa,bb,cc,dd;
    scanf("%d", &aa);
    scanf("%d", &bb);
    scanf("%d", &cc);
    scanf("%d", &dd);
    int flag = 1;
    if ((aa == 0) && (bb == 0) && (cc == 0) && (dd == 0)){
        flag = 0;
    }

    while (flag == 1){
        lock(aa,bb,cc,dd);

        scanf("%d", &aa);
        scanf("%d", &bb);
        scanf("%d", &cc);
        scanf("%d", &dd);
        
        if ((aa == 0) && (bb == 0) && (cc == 0) && (dd == 0)){
            flag = 0;
    }
}
}