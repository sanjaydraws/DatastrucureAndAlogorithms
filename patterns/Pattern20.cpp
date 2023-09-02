
/**
 * 
A
ABA
ABCB
ABCDCA
ABCDEDB
ABCDEFECA
*/


#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int n = 6;
    
    for(int row =0; row<n; row++){
        char ch;
        for(int col = 0; col< row + 1; col++){
            int number = col + 1;
             ch = number + 'A' -1;
            cout<<ch;
        }
        // print untill it reaches  A
        for(char alphabet= ch ; alphabet>'A'; alphabet = alphabet -1){
            alphabet = alphabet -1;
            cout<<alphabet;
        }
        cout<<endl;
    }
    return 0;
}