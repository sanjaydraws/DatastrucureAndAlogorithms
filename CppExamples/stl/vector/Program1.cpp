// std::vector is a dynamic array that can resize itself as elements are added or removed.

#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> myVector;

    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    for (int i : myVector) {
        cout << i << " ";
    }//10 20 30 
    cout<<endl;

    //2. pop_back()
    myVector.pop_back();
    for (int i : myVector) {
        cout << i << " ";
    }//10 20
    cout<<endl;

    //3. size()
    cout << "Size of myVector: " << myVector.size()<< endl; // Size of myVector: 2

    //4. empty()
   cout << "myVector is empty." << myVector.empty()<< endl; // myVector is empty.0

   //5. at()
   cout << "Element at index 1: " << myVector.at(1)<< endl;// Element at index 1: 20

   //6. front() and back()
    cout << "First element: " << myVector.front() << endl;
    cout << "Last element: " << myVector.back() << endl;
    //First element: 10
    // Last element: 20

    //7. clear()
    myVector.clear();
    cout << "myVector is empty." << myVector.empty() << endl; // myVector is empty.1

    //8. insert()
    vector<int> myVector1 = {10, 20, 30};
    auto it = myVector1.begin() + 1;

    myVector1.insert(it, 15);

    for (int i : myVector1) {
        cout << i << " ";
    }//10 15 20 30 
    cout<<endl;
    //9. erase()
    vector<int> myVector2 = {10, 20, 30};
    auto it1 = myVector2.begin() + 1;

    myVector2.erase(it1);

    for (int i : myVector2) {
        cout << i << " ";
    }// 10 30
    cout<<endl;

    // 10. resize()
    vector<int> myVector3 = {10, 20, 30};
    myVector3.resize(5, 0);
    for (int i : myVector3) {
        cout << i << " ";
    } // 10 20 30 0 0


    return 0;
}

//OUtput
//10 20 30 
