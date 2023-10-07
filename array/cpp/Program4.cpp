// reverse array program in cpp

#include <iostream>
using namespace std;
void reverseArray(int arr[], int size) {
  

  // for(int left =0, right=size-1; left<=right; left++, right--) {
  //  swap(arr[left], arr[right]);
  // }
  
  int left = 0;
  int right = size - 1;
  while(left <= right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
  }

  //printing the array;
  for(int i=0; i<size; i++) {
    cout << arr[i] << " "; 
  }
  
}

int main(int argc, char const *argv[])
{
    int arr[6] = {10,20,30,40,50,60};
    int size = 6;

    reverseArray(arr, size);
    return 0;
}

// output
//60 50 40 30 20 10 
