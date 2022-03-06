

// first and last position of element in array 
#include<iostream>
using namespace std;


int firstOcc(int arr[],int n, int key){
    int s = 0, e = n-1; 
    int mid = s + (e -s)/2;
    int ans = -1;
    while (s<=e)
    {
        if(arr[mid] == key){
            ans = mid ; // store when equal 
            e = mid -1; // put end to back
        }
        else if(key >arr[mid]){
            // if key is small the go to right 
            s = mid + 1 ;

        }else if(key<arr[mid]){
            // if key is bigger the go to left 
            e = mid -1;
        }

        mid = s + (e -s)/2;
    }
    return ans;
}

int lastOcc(int arr[],int n, int key){
    int s = 0, e = n-1; 
    int mid = s + (e -s)/2;
    int ans = -1;
    while (s<=e)
    {
        if(arr[mid] == key){
            ans = mid ; // store when equal 
            s = mid + 1; //
        }
        else if(key >arr[mid]){
            // if key is small the go to right 
            s = mid + 1 ;

        }else if(key<arr[mid]){
            // if key is bigger the go to left 
            e = mid -1;
        }

        mid = s + (e -s)/2;
    }
    return ans;
}

int main(){
    int even[5] = {3,3,3,3,5};
    cout<<"First Occurrence of 3 is at index "<<firstOcc(even,5,3);
        cout<<"last Occurrence of 3 is at index "<<lastOcc(even,5,3);

    return 0;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int,int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    return p;
}
