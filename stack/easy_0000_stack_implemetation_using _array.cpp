

#include<iostream>
using namespace std;
class Stack{
    private:
       int *arr;
       int topIndex;
       int capacity;
    
    public:
       Stack(int size){
        capacity = size;
        *arr = new int[5];
        topIndex = -1;
       }

       void push(int data){
        if(totopIndex == capacity-1){
            cout<<"stack is full";
            return;
        }
        arr[++topIndex] = data;
       }
       void isFull(){
        return topIndex == capacity-1;
       }
       void isEmpty(){
        return topIndex == -1;
       }
       int top(){
        if(topIndex==-1){
            cout<<stack is empty;
        }
        return arr[topIndex];
       }
       void pop(){
        if(top == -1){
            cout<<"stack is empty";
        }
        top--;
       }

};
int main(){
    Stack s1;
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
 cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    while(!s.isEmpty()){
        cout<<"pop "<<s.top<<endl;
        s.pop();
    }
    return 0;
}