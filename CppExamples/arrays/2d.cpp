


#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    //Creating and Initializing a 2D Array
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* ptr = &matrix[0][0]; // Pointer to the first element

    int matrix2[3][3]; // Creates a 3x3 matrix

    //Partial Initialization of a 2D Array
    int partialInit[2][3] = {{1, 2}, {3, 4}};


    // // Example 2: Creating and Initializing a 3D Array
    int threeDArray[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };


    // access element Using nested loops to access elements
    cout<<"Using nested loops to access elements"<<endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
    } //1 2 3 4 5 6 7 8 9

    cout<<endl;

    // access element Using loops and pointer 
    cout<<"Using loops and pointer"<<endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << *(ptr + i*3 + j) << " ";
        }
    }



    return 0;
}
