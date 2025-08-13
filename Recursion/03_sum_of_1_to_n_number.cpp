// print n numbers 

#include<stdio.h>

void printSum (int i, int n, int sum );  


int main(){
    printSum(1,5,0); // 15 
}

void printSum(int i, int n, int sum){
    if(i== n){
        sum +=i;
        printf("total sum = %d\n",sum);
        return;
    }
    sum += i;
    printSum(i + 1, n, sum); 
}