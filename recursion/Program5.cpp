// fibonacci sequence till nth term 

#include<stdio.h>

void printFibonacciSeq(int a, int b, int n){
    if(n==0) return;
    int c = a + b;
    printf("num = %d\n",c);
    printFibonacciSeq(b, c, n-1 );
}

int main(){
    int a = 0, b =1, n=7;

    printf("num = %d\n",a);
    printf("num = %d\n",b);
    printFibonacciSeq(a, b, n-2);

}
/**
 * num = 0
num = 1
num = 1
num = 2
num = 3
num = 5
num = 8
*/