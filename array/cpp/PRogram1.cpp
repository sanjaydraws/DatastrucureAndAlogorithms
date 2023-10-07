// minimum number in an array 

#include<limits.h>
#include <iostream>

using namespace std;
int findMinimumInArray(int arr[], int size){
    int minAns = INT_MAX;
    for(int  i = 0 ; i < size ; i++){
        if(arr[i] < minAns){
            minAns = arr[i];
        }
    }
    return minAns;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,8,31,4,3,1,-51};
    int size = 7;
      // // -2 to the  power 31
    // cout << INT_MIN << endl;
    // //2 to the power 31 - 1
    // cout << INT_MAX << endl;

    int minimum = findMinimumInArray(arr, size);
    cout << "Minimum number is: " << minimum << endl;//Minimum number is: -51
    return 0;
}
