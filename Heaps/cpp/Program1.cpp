//// Heap implementation 

//Heap creation: TC: O(n)
// insertion : T.c - O(log n)
// deletion : to access root node T.C O(log n)
// - nsize array to convert in Heap - O(n)

//Heap - find max and find min -O(1) and on array takes : O(n)


#include<iostream>
using namespace std;

class Heap{
    public:
       int *arr;
       int capacity;
       int size;

       Heap(int capacity){
           this->arr = new int[capacity];
           this->capacity = capacity;
           // size = current number of element in Heap
           this->size = 0;
       }
       /**
        * insert element in Heap
        */
       void insert(int value){
           if(size == capacity){
               cout<<"Heap Overflow";
               return;
           }
           //size will be incresed in insertions
           size++;
           int index = size; 
           arr[index] = value; // starts assigning from 1 index 

           // take the value to it's current position 
           while(index > 1){
               int parentIndex = index/2;
               if(arr[index] > arr[parentIndex]){
                   swap(arr[index],arr[parentIndex]);
                   index = parentIndex;
               }else{
                   break;
               }
           }
       }
       void printHeap(){
           for(int i = 1;i<=size;i++){
               cout << arr[i] << " ";
           }
       }
       /**
        * delete element in Heap
        */
       int deleteFromHeap(){
           int answer = arr[1];
           //assign last element to rootnode 
           arr[1] = arr[size];
           // delete last element from it's original position
           size--;
           int index = 1;
           while(index < size){
               int leftIndex = 2*index;
               int rightIndex = 2*index+1;
               int largestOfIndex = index; // assume root node has big value
               //find out which one has bigger value
               // check left child
               if(leftIndex <= size && arr[largestOfIndex] < arr[leftIndex]){
                   largestOfIndex = leftIndex;
               }
               if(rightIndex <= size && arr[largestOfIndex] < arr[rightIndex]){
                   largestOfIndex = rightIndex;
               }

               // if no change
               if(index == largestOfIndex){
                   break;
               }else{
                   swap(arr[index],arr[largestOfIndex]);
                   index = largestOfIndex;
               }
           }
           return answer;
       }

};
int main(){
    Heap h(20);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    cout<<"println the content of Heap: "<<endl;    
    h.printHeap(); 

    int ans = h.deleteFromHeap();

    cout<<"deleted element"<<ans<<endl;
    cout<<"printing the content of heap : "<<endl;
    h.printHeap();

}

/**
println the content of Heap: 
20 11 5 10 6 deleted element20
printing the content of heap : 
11 10 5 6 

*/