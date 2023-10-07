

#include<limits.h>
#include <iostream>
using namespace std;

// count 1 and zero in an array 
void countZeroOne(int arr[], int size) {
  int zeroCount = 0;
  int oneCount = 0;

  for(int i=0; i<size; i++) {
    if(arr[i] == 0) {
      zeroCount++;
    }
    if(arr[i] == 1) {
      oneCount++;
    }
  }

  cout << "ZeroCount: " << zeroCount << endl;
  cout << "oneCOunt: " << oneCount << endl;
  
}
int main(int argc, char const *argv[])
{
    int arr[] = {0,0,0,1,1,0,1,0,1,0,1,0,1,1,1};

    int size = 15;
    countZeroOne(arr,size);
    return 0;
}

// output
// ZeroCount: 7
// oneCOunt: 8