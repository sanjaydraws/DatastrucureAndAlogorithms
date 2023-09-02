#include <iostream>
using namespace std;

int main(){
   	int num;
	cin >>num;    //Reading input from STDIN
	for(int i=1 ; i<=num;i++){
		if(i%15 == 0){
			cout << "FizzBuzz\n";
		}
		else if(i%3 == 0){
			cout << "Fizz\n";
		}
		else if(i%5 == 0){
			cout << "Buzz\n";
		}
		else{
			cout <<i<<"\n";
		}
	}
		// Writing output to STDOUT
		return 0;
}