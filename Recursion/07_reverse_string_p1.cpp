#include<stdio.h>
#include<vector> 
#include<iostream>
#include<string> 
using namespace std;

class Solution {
public:
	void rev(vector<char>& str, int l, int r){
		if(l >= r){
			return;
		}
		swap(str[l++], str[r--]);                            
		rev(str, l, r);
    }
	void reverseString(vector<char>& s) {
		rev(s, 0, s.size() - 1);
	}
};

int main(int argc, char const *argv[])
{
    std::vector<char> input({ 'a', 'b', 'c' });
    Solution obj1 ; 
    obj1.reverseString(input);


    return 0;
}
