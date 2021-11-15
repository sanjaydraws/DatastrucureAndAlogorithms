// tower of hanoi 
#include<String>
#include<stdio.h>

// t.c  O(2^n -1) = O(2^n)
void towerOfHanoi(int n, int A, int B, int C){
    if(n >0)
    {
        towerOfHanoi(n-1, A, C, B);
        printf("\nMove a disc from %d to %d", A,C);
        towerOfHanoi(n-1, B, A, C);

    }

}
int main(int argc, char const *argv[])
{
    int n =3;
    towerOfHanoi(n, 1,2,3);
    return 0;
}
