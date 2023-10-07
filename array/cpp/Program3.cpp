// extreme print element of an array 
#include <iostream>
using namespace std;

void extremePrint(int arr[], int size) {
  int left = 0;
  int right = size - 1;

  while(left <= right) {
    if(left == right) {
      cout << arr[left] << endl;  
    }
    else {
      cout << arr[left] << endl;
      cout << arr[right] << endl;
    }
    
    left++;
    right--;
  }
  
}
int main(int argc, char const *argv[])
{
    int arr[6] = {10,20,30,40,50,60};
    int size = 6;
    extremePrint(arr, size) ;
    return 0;
}

/**
 Output
 10
60
20
50
30
40
*/