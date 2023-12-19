//Dp - // store the value of subproblem in map or table 
// TopDown Approach/ Memoization
// Bottomup approach | Tabulation 



#include<iostream>
#include<vector>
using namespace  std;

// topdown approach | Recursive | Memoization
//T.C - O(n)
//S.C - O(n) + O(n) => O(n)
int fib(int n,vector<int> &dp){
    //base case
    //step 1
    if(n <=1){
        return n;
    }
    //step 3
    if(dp[n] != -1){
        return dp[n];
    }
    
    // step 2
    dp[n] =  fib(n - 1,dp) + fib(n - 2,dp);
    return dp[n];
}

// Bottomup approach | Tabulation 
//T.C - O(n)
//S.C - O(n)
int fib2(int n, vector<int> &dp ){
    // step 2
    dp[1] = 1;
    dp[0] = 0;
    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// space optimization
//  T.C O(N)
// S.C O(1)
int fib3(int n){
    int prev1 = 1;
    int prev2 = 0;
    if(n == 0){
        return prev2;
    }
    for(int i = 2;i<=n;i++){
        int curr = prev1 + prev2;

        //shift logic
        prev2 = prev1 ;
        prev1 = curr;
    }
    cout<< prev1<<endl;
    return prev1;
}

int main(){
    int n = 6;

    vector<int> dp(n + 1, -1);  // Initialize dp with size n+1 and fill with -1


    
    cout<<fib(n,dp)<<endl;

    vector<int> dp2(n + 1, -1); 
    cout<<fib2(n,dp2)<<endl;


    cout<<fib3(n);


}

//Fibonacci(6) = 8
