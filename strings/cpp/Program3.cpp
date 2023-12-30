
// demo of string functions in cpp
#include <iostream>
#include <string.h>

using namespace std;

int main() {
  string name;
  getline(cin, name);

  // declare empty string
  string temp = "";

  cout << "Length of string: "  << name.length() << endl;
  cout << "String is empty or not: " << temp.empty() << endl;
  cout <<"Character at position 0 is: " << name.at(0) << endl;

  cout << "Front character of string is: "<< name.front() << endl;
  cout << "back character of string is: "<< name.back() << endl;

  string str1 = "Justin";
  string str2 = "Bieber";

  cout << "before appending" << endl;
  cout << str1 << endl;
  cout << str2 << endl;

  //apend a string
  str1.append(str2);

  cout << "After appending" << endl;
  cout << str1 << endl;
  cout << str2 << endl;


  string title = "Welcome to the jungle";
  title.erase(4, 3);
  cout << title << endl;


  string desc = "Hello Hi ";
  string s3 = "Hola";

  desc.insert(5, s3);

  cout << "Printing name:  " << desc << endl;


  string s4 = "Hello world";

  cout << s4 << endl;

  s4.push_back('1');
  cout << s4 << endl;

  s4.pop_back();
  cout << s4 << endl;


  string s5 = "Grace Alexander Thompson ";
  string s6  = "Thompson";



  if(s5.find(s6) == string::npos){
   //not found
   cout << "Not FOund" << endl;
  }
  else {
   cout << "Found" << endl;
  }

  string s7 = "Rohit";
  string s8 = "Rohit";

  if(s7.compare(s8) == 0) {
   cout << "Matching" << endl;
  }
  else {
   cout << "not matching " << endl;
  }

  string s9 = "Chronicles of the Enigmatic Cosmos";
  cout << s9.substr(19, 5) << endl;

  
  return 0;
}

/**
Coding Friction
Length of string: 15
String is empty or not: 1
Character at position 0 is: C
Front character of string is: C
back character of string is: n
before appending
Justin
Bieber
After appending
JustinBieber
Bieber
Welc to the jungle
Printing name:  HelloHola Hi 
Hello world
Hello world1
Hello world
Found
Matching
nigma
*/