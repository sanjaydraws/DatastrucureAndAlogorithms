// https://leetcode.com/problems/row-with-maximum-ones/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
      int n = mat.size();
      int oneCount = INT32_MIN; 
      int rowNum = 0;
      vector<int> ans;
      for(int i = 0; i<n ; i++){
          int count = 0;
          for(int j = 0; j< mat[i].size(); j++){
              if(mat[i][j] ==1){
                count ++;
              }
            }
          if(count>oneCount){
            oneCount = count;
            rowNum = i;
          }
        }
      ans.push_back(rowNum);
      ans.push_back(oneCount);
      return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 0, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1}
    };

    Solution sol;
    vector<int> result = sol.rowAndMaximumOnes(mat);

    cout << "Row with Maximum Ones: " << result[0] << endl;
    cout << "Count of Ones in that Row: " << result[1] << endl;

    return 0;
}
/**Output
Row with Maximum Ones: 3
Count of Ones in that Row: 4

*/