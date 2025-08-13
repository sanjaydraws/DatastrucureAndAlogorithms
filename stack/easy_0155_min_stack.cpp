#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; // Regular values
    stack<int> minStack;  // Track minimums

public:
    // Step 1: Initialize both stacks
    MinStack() {}

    // Step 2: Push a new element
    void push(int val) {
        mainStack.push(val); // Always push to mainStack

        // If minStack is empty or val is new min, push it
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            // Otherwise repeat the current minimum
            minStack.push(minStack.top());
        }
    }

    // Step 3: Pop from both stacks
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }

    // Step 4: Return top of mainStack
    int top() {
        return mainStack.top();
    }

    // Step 5: Return top of minStack (current minimum)
    int getMin() {
        return minStack.top();
    }
};

// Driver code to simulate operations
int main() {
    MinStack st;

    st.push(5); // main = [5], min = [5]
    st.push(2); // main = [5,2], min = [5,2]
    st.push(4); // main = [5,2,4], min = [5,2,2]

    cout << "Current Min: " << st.getMin() << endl; // Output: 2
    st.pop();  // Removes 4
    cout << "After pop, Min: " << st.getMin() << endl; // Output: 2
    st.pop();  // Removes 2
    cout << "After another pop, Min: " << st.getMin() << endl; // Output: 5

    return 0;
}

/***
 * 
 * 
 * 
 * Push 5 → main: [5],      min: [5]
Push 2 → main: [5, 2],   min: [5, 2]
Push 4 → main: [5,2,4],  min: [5,2,2]
getMin() => 2

pop()    → removes 4     → min: [5,2]
getMin() => 2

pop()    → removes 2     → min: [5]
getMin() => 5


 */

 /* 
 T.c
Operation	Time Complexity	Reason
push(x)	O(1)	One push on mainStack and one on minStack
pop()	O(1)	One pop from each stack
top()	O(1)	Access top of mainStack
getMin()	O(1)	Access top of minStack

S.c
MainStack	O(n)
minStack	O(n)
*/