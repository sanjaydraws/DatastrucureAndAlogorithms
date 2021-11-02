
#include<stdio.h>

// for n>1 
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.

int fib1(int n){
    if(n<2) return n;
    return fib1(n-1) + fib1(n-2);
}

 int fib2(int n)
 {
        if(n <= 1)
            return n;
        
		int a = 0, b = 1;
		
		while(n-- > 1)
		{
			int sum = a + b;
			a = b;
			b = sum;
		}
        return b;
}

int main(){
    int a = 0, b =1, n=7;
    printf("num = %d\n",fib2(n));
}