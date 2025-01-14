// using priority_queue for heap 


#include<iostream>
#include<queue>
using namespace std;

int main(){
    //max heap
    priority_queue<int> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    cout << "Size: " << pq.size() << endl;
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();

    cout << "Size: " << pq.size() << endl;
    if(pq.empty()) {
        cout << "Max heap is empty" << endl;
    }else{
        cout << "Max heap is not empty" << endl;
    }
    return 0;
}

/***
Output
Size: 5
top element: 9
top element: 8
top element: 6
top element: 4
top element: 3
Size: 0
Max heap is empty

*/