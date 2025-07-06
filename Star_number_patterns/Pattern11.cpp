/**
 * 
 * 
 * Hollow Pyramid
 * 
 -------------------
   *
  * *
 *   *
*     *

*/

#include <iostream>
using namespace std;

int main() {
    int num = 4;
    for(int row = 0; row<num;row = row+1){
        for(int col = 0; col<num-row-1;col = col +1){
            cout<<" ";
        }
        for(int col = 0; col<row+1;col = col +1){
            // for first and last column print star
            if(col == 0 || col == row + 1 -1 ){
                cout<<"* ";
            }else{
                cout<< "  ";
            }
        }
        cout<<endl;
    }

    return 0;
}