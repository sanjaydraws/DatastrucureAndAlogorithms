#include <iostream>
#include<string.h>
using namespace std;


// find string length
int findLength(char ch[], int size) {
  int index = 0;
  while(ch[index] != '\0') {
    index++;
  }
  return index;


  // int length = 0;

  // for(int i=0; i<size; i++) {
  //  if(ch[i] == '\0') {
  //    break;
  //  }
  //  else {
  //    length++;
  //  }
  // }

  // return length;
}

//reverse string
void reverseString(char ch[] , int n) {
  int i=0; 
  int j = n-1;

  while(i<=j) {
    swap(ch[i], ch[j]);
    i++;
    j--;
  }

}

void convertToUpperCase(char ch[], int n) {

  int index = 0;

  while(ch[index] != '\0') {

    //check if lowercase, then convert to upper case
    if(ch[index] >= 'a' && ch[index] <='z') {
      ch[index] = ch[index] - 'a' + 'A';
    }
    index++;
  }
}

void replaceCharacter(char ch[], int n) {
  int index = 0;

  while(ch[index] != '\0') {
    if(ch[index] == '@') {
      //insert space
      ch[index] = ' ';
    }
    index++;
  }
}

// string is palindrome or not
bool checkPalindrome(char ch[], int n) {
  //n  is length of string
  int i=0; 
  int j = n-1;

  while( i<= j) {
    if(ch[i] == ch[j]) {
      i++;
      j--;
    }
    else {
      //characters are not matching
      return false;
    }
  }
  return true;

}


int main() {
  char ch[100];

  // //cin >> ch;
  cin.getline(ch, 100);

  int len = findLength(ch, 100);

  //ex: 'radar' is palindrom
  bool isPalindrome = checkPalindrome(ch, len);

  if(isPalindrome) {
   cout << "Valid Palindrome" << endl;
  }
  else {
   cout << "Invalid Palindrome" << endl;
  }

  char str1[] = "Hello@World";
  cout << "before " << str1 << endl;
  replaceCharacter(str1,100);
  // convertToUpperCase(str1, 100);
  cout << endl << "after " << str1 << endl;



  cout << "Before " << str1 << endl;

  int len1 = findLength(str1, 100);

  reverseString(str1,len1);

  cout<<endl << "After " << str1 << endl;



  cout << "printing length str1: " << strlen(str1) << endl;


  return 0;
}
/**
Output:
radar
Valid Palindrome
before Hello@World

after Hello World
Before Hello World

After dlroW olleH
printing length: 11

*/