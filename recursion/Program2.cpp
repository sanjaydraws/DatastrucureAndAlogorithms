// print numbers 5  to 1 
#include<stdio.h>
void printNumb (int);  

int main(){
   printNumb(5);
   return 0;
}

void printNumb(int n){
    if(n==0)
      return;
    printf("num = %d\n",n);
    printNumb(n-1);  
}