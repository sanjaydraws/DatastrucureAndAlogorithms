/*
Hollow inverted half pyramid
*****
*  *
* *
**
*

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int n = 5;
    for(int row = 0; row<n;row++){
        for(int col = 0; col <n-row; col++){
            // first and last row print star
            if(row ==0 || row == n-1){
                cout<< "*";
            }else{
                // first col last col print start
                if(col ==0 || col == n -row -1){
                    cout<< "*";
                }else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
}