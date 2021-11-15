#include<iostream>
using namespace std;

 int first = -1 ;
 int  last = -1;
void findOccurance(const string& str ,int idx, char element
 ){
     if(idx == str.length()){
         cout<< first<<endl;
         cout<< last;
         return;
     }
    const char curChar = str[idx];
    if(curChar == element){
        if(first == -1){
            first = idx;
        }else{
            last = idx;
        }
    }
    findOccurance(str, idx+ 1, element);
}
int main()
{
    string str = "abaacdaefabah";
    findOccurance(str, 0, 'b');


}
// first -0 
// last - 10 
