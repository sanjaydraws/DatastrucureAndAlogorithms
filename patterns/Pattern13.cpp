

/**
 * 
 * 
 * Hollow pyramid
 
*         *
 *       *
  *     *
   *   *
    * *
     *

*/

#include <iostream>
using namespace std;

int main(){
    int n = 6;
    for(int row = 0;row<n;row++){
        for(int col = 0; col<row;col++){
            cout<<" ";
        }
        int totalCol = n-row;
        for(int col = 0; col<totalCol;col++){
            // if first or last col 
            if(col == 0 ||col == totalCol - 1)
             cout<<"* ";
            else
                cout<<"  ";
        
        }
        
        cout<<endl;
    }
    return 0;
}