#include <bits/stdc++.h>
using namespace std;



// solution 1
void genPermute(vector<string>& a, int i, vector<vector<string>>& out) {
    int n = a.size();
    if (i == n) {
        out.push_back(a);      // one permutation complete
        return;
    }
    for (int j = i; j < n; ++j) {
        swap(a[i], a[j]);      // choose a[j] for position i
        genPermute(a, i+1, out);
        swap(a[i], a[j]);      // backtrack (restore)
    }
}

int main() {
    vector<string> words = {"ab", "bc", "cd"};
    vector<vector<string>> perms;
    genPermute(words, 0, perms);

    // print permutations
    for (auto &p : perms) {
        for (int k = 0; k < (int)p.size(); ++k) {
            cout << p[k] << (k+1==(int)p.size() ? "" : ", ");
        }
        cout << '\n';
    }
    return 0;
}



// ==============================================

// solution 2 : using recursion

#include <bits/stdc++.h>
using namespace std;

void rec(vector<string>& words, vector<bool>& used, vector<string>& curr, vector<vector<string>>& all) {
    if (curr.size() == words.size()) {
        all.push_back(curr); // ek permutation complete
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (!used[i]) {
            used[i] = true;              // use word[i]
            curr.push_back(words[i]);    // add to current path
            rec(words, used, curr, all); // recurse
            curr.pop_back();             // backtrack
            used[i] = false;             // mark unused
        }
    }
}

int main() {
    vector<string> words = {"ab", "bc", "cd"};
    vector<vector<string>> all;
    vector<string> curr;
    vector<bool> used(words.size(), false);

    rec(words, used, curr, all);

    // print
    for (auto &p : all) {
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << (i+1 == p.size() ? "" : ", ");
        }
        cout << "\n";
    }
}

/*
Start:
curr = {}
used = {0,0,0}

|-- i=0 → pick "ab" (used[0]=true)
|   curr = {ab}, used = {1,0,0}
|   |
|   |-- i=1 → pick "bc" (used[1]=true)
|   |   curr = {ab, bc}, used = {1,1,0}
|   |   |
|   |   |-- i=2 → pick "cd" (used[2]=true)
|   |       curr = {ab, bc, cd}, used = {1,1,1} ✅ [ab, bc, cd]
|   |       return → pop_back() cd, used[2]=false
|   |
|   |-- i=2 → pick "cd" (used[2]=true)
|       curr = {ab, cd}, used = {1,0,1}
|       |
|       |-- i=1 → pick "bc" (used[1]=true)
|           curr = {ab, cd, bc}, used = {1,1,1} ✅ [ab, cd, bc]
|           return → pop_back() bc, used[1]=false
|       return → pop_back() cd, used[2]=false
|   return → pop_back() ab, used[0]=false

|-- i=1 → pick "bc" (used[1]=true)
|   curr = {bc}, used = {0,1,0}
|   |
|   |-- i=0 → pick "ab" (used[0]=true)
|   |   curr = {bc, ab}, used = {1,1,0}
|   |   |
|   |   |-- i=2 → pick "cd" (used[2]=true)
|   |       curr = {bc, ab, cd}, used = {1,1,1} ✅ [bc, ab, cd]
|   |       return → pop_back() cd, used[2]=false
|   |
|   |-- i=2 → pick "cd" (used[2]=true)
|       curr = {bc, cd}, used = {0,1,1}
|       |
|       |-- i=0 → pick "ab" (used[0]=true)
|           curr = {bc, cd, ab}, used = {1,1,1} ✅ [bc, cd, ab]
|           return → pop_back() ab, used[0]=false
|       return → pop_back() cd, used[2]=false
|   return → pop_back() bc, used[1]=false

|-- i=2 → pick "cd" (used[2]=true)
    curr = {cd}, used = {0,0,1}
    |
    |-- i=0 → pick "ab" (used[0]=true)
    |   curr = {cd, ab}, used = {1,0,1}
    |   |
    |   |-- i=1 → pick "bc" (used[1]=true)
    |       curr = {cd, ab, bc}, used = {1,1,1} ✅ [cd, ab, bc]
    |       return → pop_back() bc, used[1]=false
    |   return → pop_back() ab, used[0]=false
    |
    |-- i=1 → pick "bc" (used[1]=true)
        curr = {cd, bc}, used = {0,1,1}
        |
        |-- i=0 → pick "ab" (used[0]=true)
            curr = {cd, bc, ab}, used = {1,1,1} ✅ [cd, bc, ab]
            return → pop_back() ab, used[0]=false
        return → pop_back() bc, used[1]=false
    return → pop_back() cd, used[2]=false

    */