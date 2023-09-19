#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int n = 5;
    for(int row = 0; row<n;row++){
        for(int col = 0;col<row+1;col++){
            if(col == 0 || col == row  || row = n -1 ){
                cout<<col+1;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;    
}