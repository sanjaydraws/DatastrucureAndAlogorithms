/**
 * factorial of n 
*/

#include<stdio.h>
int calculateFactorial (int n ){
    if(n==1 || n ==0 ){
        return 1; 
    }
    int fact_nm1 = calculateFactorial(n -1 );
    int fact_n = n * fact_nm1; 
    return fact_n;
}
int main(){
    int n = 5;
    printf("fact = %d\n",calculateFactorial(5)); //fact = 120

}