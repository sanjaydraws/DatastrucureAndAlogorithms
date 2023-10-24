// Missing elements from an array with duplicates
// array elements 1 to n
// ip : 1,3,3,3,5
// op : 2, 4
#include<iostream>
#include<algorithm>
using namespace std;

void  findMissing(int *a, int n){
    // Method1: visited method
    //TC: O(n) SC : O(1)
    for(int i = 0; i<n;i++){
        int index = abs(a[i]);
        if(a[index -1] > 0){
            a[index -1] *= -1;
        }
    }
  // for(int i = 0; i<n; i ++){
  //     // if(a[i] >0){
  //         cout<<a[i];
  //     // }
  // }
    // all posotive index are missing
    for(int i = 0; i<n; i ++){
        if(a[i] >0){
            cout<<i+1<<" ";
        }
    }
}
    // M2 : Sorting method
void  findMissingM2(int *a, int n){
    int i = 0;
    while(i<n){
        int index = a[i] -1;
        if(a[i] != a[index]){
            swap(a[i],a[index]);
        }else{
            ++i;
        }
    }

    for(int i = 0;i<n;i++){
        if(a[i]!=i+1){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int n;
    int arr[] = {1,3,3,3,5};
    n = sizeof(arr)/sizeof(int);
    findMissing(arr,n); // 2 4 
    return 0;
}