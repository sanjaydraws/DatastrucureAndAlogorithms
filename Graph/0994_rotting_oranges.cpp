//https://leetcode.com/problems/rotting-oranges/description/
//994. Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int, int, int>> q;
        int fresh=0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;

        int minutes = 0;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0 , 1, -1};

        while(!q.empty()){
            auto [x, y, time] = q.front(); q.pop();
            minutes = max(minutes, time);
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dx[y];
                if(nx >=0 && ny >=0 && nx < m && ny < n && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx, ny, time + 1});
                    fresh--;
                }
            }
        } 
        return (fresh == 0) ? minutes : -1; 
    }
};