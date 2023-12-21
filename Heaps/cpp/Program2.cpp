// create Heap from an array 
//to find out leaf node in complete binary tree(n/2 +1)th ---> nth node -- all are leaf node

#include<iostream>
using namespace std;

// Heapyfycation 
void Heapify(int *arr, int n, int index){
    int leftIndex = 2*index;
    int rightINdex = 2*index+1;
    int largestOfIndex = index;

    // find the max between three
    if(leftIndex <= n && arr[leftIndex] > arr[largestOfIndex]){
        largestOfIndex = leftIndex;
    } 
    if(rightINdex <= n && arr[rightINdex] > arr[largestOfIndex]){
        largestOfIndex = rightINdex;
    }
    //after these 2 conditions largestKaIndex will be pointing towards largest elemnt among 3 
    if(index != largestOfIndex){
        swap(arr[index], arr[largestOfIndex]);
        // now handle by recursion 
        index = largestOfIndex;
        Heapify(arr, n, index);
    }
}

////  nsize array to convert in Heap - O(n)
// running this loop n/2
void buildHeap(int arr[], int n){
    for(int index = n/2; index > 0; index--){
        Heapify(arr, n, index);
    }
}

//Heap sort
//TC - O(n log n) --  heapyfy n elements
void heapSort(int arr[], int n){
    // stop when size in 1
    while(n!=1){
        swap(arr[1], arr[n]);// arr[n] because indxing starts from zero index
        n--;
        Heapify(arr,n,1); // 1 is for root index
    }
}
int main(){ 
    int arr[] = {-1, 5, 15,20,56,32,12};
    int n = 6;
    buildHeap(arr,n);

    cout<<"printing Heap: "<<endl;
    for(int i = 1; i<=6;i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    cout<<"Printing Heap: "<<endl;
    for(int i = 1; i<=6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

/**
 printing Heap: 
56 32 20 15 5 12 
Printing Heap: 
5 12 15 20 32 56 
*/