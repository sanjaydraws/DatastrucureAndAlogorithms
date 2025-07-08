/*
// 📌 Question:
// You want to choose 3 pizza toppings out of 6 available. 
// How many different combinations are possible (order doesn't matter)?

This program generates all such combinations using backtracking.

🍕 Toppings List:
- Cheese
- Pepperoni
- Mushrooms
- Olives
- Onions
- Tomatoes

✅ Output (Example):
Total topping combinations: 20
Combinations:
Cheese  Pepperoni  Mushrooms  
Cheese  Pepperoni  Olives  
Cheese  Pepperoni  Onions  
...
Olives  Onions  Tomatoes
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to generate all combinations
void generateCombinations(int start, int n, int k, vector<string>& toppings, vector<string>& path, vector<vector<string>>& result) {
    if (path.size() == k) {
        result.push_back(path);
        return;
    }

    for (int i = start; i < n; ++i) {
        path.push_back(toppings[i]); // Choose
        generateCombinations(i + 1, n, k, toppings, path, result); // Explore
        path.pop_back(); // Backtrack
    }
}

int main() {
    // List of available toppings
    vector<string> toppings = {
        "Cheese", "Pepperoni", "Mushrooms", "Olives", "Onions", "Tomatoes"
    };

    int k = 3; // Choose 3 toppings
    int n = toppings.size();

    vector<vector<string>> result;
    vector<string> path;

    generateCombinations(0, n, k, toppings, path, result);

    cout << "Total topping combinations: " << result.size() << endl;
    cout << "Combinations:\\n";

    for (const auto& comb : result) {
        for (const string& t : comb)
            cout << t << "  ";
        cout << endl;
    }

    return 0;
}

