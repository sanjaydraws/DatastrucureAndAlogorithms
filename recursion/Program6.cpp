/**
 * stack height 
*/

// print x^n (stack height = n)

#include<stdio.h>

int calcPower(int x, int n){
    if(n==0) return 1;
    if(x == 0) return 1;
    int xPowernm1 = calcPower(x, n-1);
    int xPown = x * xPowernm1;
    return xPown;
}
int main(int argc, char const *argv[])
{
    int x = 2, n = 5;
    int ans = calcPower(x, n);   
        printf("ans = %d\n",ans); // 32

    return 0;
}

