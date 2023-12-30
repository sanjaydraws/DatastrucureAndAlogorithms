
// Demo creation of character array

#include <iostream>

using namespace std;

int main(){
  //creation of character array
  char ch[100];
  // taking input 
  //cin >> ch;
  cin.getline(ch, 100);
  //print
  cout<< "Printing the value of ch: " << ch << endl;

  //printing using loop
  for(int i=0; i<10; i++) {
    cout <<"At Index: " << i << " " << ch[i] << endl;
  }

  char temp = ch[6];
  int value = (int)temp;
  cout << "printing integer value: " << value << endl;

  return 0;
}
/**
Output:
Virat Kohli
Printing the value of ch: Virat Kohli
At Index: 0 V
At Index: 1 i
At Index: 2 r
At Index: 3 a
At Index: 4 t
At Index: 5  
At Index: 6 K
At Index: 7 o
At Index: 8 h
At Index: 9 l
printing integer value: 75

*/