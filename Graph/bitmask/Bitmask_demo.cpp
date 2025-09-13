#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> grid = {
        {'@', 'a', 'b'},
        {'c', 'd', 'e'},
        {'f', '.', '.'}
    };

    int n = grid.size(), m = grid[0].size();
    int allKeys = 0;

    // 1. find start and total keys
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c = grid[i][j];
            // if (c == '@') sr=i, sc=/;
            if (c >= 'a' && c <= 'f') {
                allKeys |= (1 << (c - 'a'));
            }
        }
    }

    cout << "Decimal value of allKeys: " << allKeys << endl;
    cout << "Binary value of allKeys : " << bitset<8>(allKeys) << endl;

    return 0;
}
//Decimal value of allKeys: 63
// Binary value of allKeys : 00111111