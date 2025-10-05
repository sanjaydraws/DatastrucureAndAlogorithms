#include <bits/stdc++.h>
using namespace std;

// Maximum number of nodes (you can change)
const int N = 1000;

// parent[i] -> parent of node i
// size[i] -> size of the set (used for union by size)
int parent[N];
int sizeArr[N];

// --------------------------
//  1. Make Set Function
// Each node is its own parent initially
void make_set(int v) {
    parent[v] = v;
    sizeArr[v] = 1;
}

// --------------------------
//  2. Find Set Function
// Finds the leader (representative) of the set of 'v'
// Uses Path Compression to speed up future lookups
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // path compression
}

// --------------------------
//  3. Union Sets Function
// Joins two sets (if they are different)
// Uses Union by Size (attach smaller tree to larger)
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizeArr[a] < sizeArr[b]) 
            swap(a, b); // ensure 'a' is bigger
        parent[b] = a;  // attach smaller tree (b) to larger (a)
        sizeArr[a] += sizeArr[b];
    }
}

int main() {
    // Create 6 nodes: 1 to 6
    for (int i = 1; i <= 6; i++)
        make_set(i);

    // Union some nodes
    union_sets(1, 2);
    union_sets(2, 3);
    union_sets(4, 5);

    // Check if 1 and 3 are in same set
    if (find_set(1) == find_set(3))
        cout << "1 and 3 are in the same set\n";
    else
        cout << "1 and 3 are in different sets\n";

    // Check if 3 and 5 are in same set
    if (find_set(3) == find_set(5))
        cout << "3 and 5 are in the same set\n";
    else
        cout << "3 and 5 are in different sets\n";

    // Union 3 and 5
    union_sets(3, 5);

    // Now they should be in same set
    if (find_set(3) == find_set(5))
        cout << "Now 3 and 5 are in the same set\n";

    return 0;
}
/**

find_set(v) = find karta hai v kis leader ke group me hai

path compression = future calls fast karne ke liye har node ko directly leader se jod deta hai
Swap logic: Always keep the bigger set on top and attach the smaller set under it.
This keeps the tree short, so both find and union work faster. ✅

 * T.C: 
 * 
 * find_set	O(α(N)) ≈ O(1)
union_sets	O(α(N)) ≈ O(1)
(α = inverse Ackermann function, which is almost constant)

Space Complexity:

O(N) — for parent[] and sizeArr[] arrays.
 */