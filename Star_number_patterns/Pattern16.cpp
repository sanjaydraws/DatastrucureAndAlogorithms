
/**
*
 
1
2*2
3*3*3
4*4*4*4
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){

    int n = 4;

    // for(int row = 0;row<n;row++){
    //     for(int col = 0; col <2*row+1;col++ ){
    //         // print * for odd number
    //         if(col%2==1){
    //             cout<<"*"; 
    //         }else{
    //             cout<<row+1;
    //         }
    //     }
    //     cout<<endl;
    // }

    // without even odd number
    for(int row = 0;row<n;row++){
        int totalCol = row + 1;
        for(int col = 0; col<totalCol;col++ ){
            if(col == totalCol - 1){
                cout<<row+1; // for last column
            }else{
                cout<<row+1<<"*";
            }
            
        }
        cout<<endl;
    }
}