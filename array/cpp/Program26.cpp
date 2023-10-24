//move all negative number to left side of an array Program

// M-1 sort() T.C-> O(n log n) SC - O(n)
// M-2
// Dutch National flag algo 
//TC - O(n) SC - O(1)
#include <iostream>
using namespace std;
void moveAllNegativeToLeft(int *a, int n){
  int l = 0,h = n-1;
  while(l<h){
    if(a[l] < 0){
      l++;
    }else if(a[h] > 0){
      h--;
    }else{
      swap(a[l], a[h]);
    }
  }
    
}
int main() {
  int arr[] = {-1, 3, -5, 6, -3, 2, -8, -7};
  int n = sizeof(arr)/sizeof(arr[0]);

  std::cout << "Original Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  moveAllNegativeToLeft(arr, n);

  std::cout << "Modified Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}

