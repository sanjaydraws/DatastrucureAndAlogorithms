
// https://leetcode.com/problems/number-of-islands/description/
//200. Number of Islands
/*
// Time Complexity: O(m * n) - each cell processed once
// Space Complexity: 
//    DFS -> O(m * n) (recursion stack in worst case)
//    BFS -> O(m * n) (queue in worst case)

*/
class Solution1 {
public:
    // ---------------- DFS ----------------
    void dfs(int x, int y, vector<vector<char>>& grid, vector<int>& dx, vector<int>& dy) {
        grid[x][y] = '0'; // mark visited
        int m = grid.size();
        int n = grid[0].size();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                dfs(nx, ny, grid, dx, dy);
            }
        }
    }

    // ---------------- BFS ----------------
    void bfs(int x, int y, vector<vector<char>>& grid, vector<int>& dx, vector<int>& dy) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({x, y});
        grid[x][y] = '0'; // mark visited

        while (!q.empty()) {
            auto [cx, cy] = q.front(); 
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                    grid[nx][ny] = '0';   // mark visited
                    q.push({nx, ny});
                }
            }
        }
    }

    // ---------------- Using DFS ----------------
    int numIslandsDFS(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, dx, dy);
                }
            }
        }
        return count;
    }

    // ---------------- Using BFS ----------------
    int numIslandsBFS(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(i, j, grid, dx, dy);
                }
            }
        }
        return count;
    }
};


//Approach 3- Union-Find (DSU) Approach

class Solution2 {
public:
    int findParent(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = findParent(parent[x], parent); // path compression
        }
        return parent[x];
    }

    void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = findParent(a, parent);
        int pb = findParent(b, parent);

        if (pa == pb) return;

        if (rank[pa] < rank[pb]) parent[pa] = pb;
        else if (rank[pa] > rank[pb]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> parent(m * n, -1);
        vector<int> rank(m * n, 0);

        // Initialize parent for each '1'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int id = i * n + j;
                    parent[id] = id;
                }
            }
        }

        // Union neighbors
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int id1 = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == '1') {
                            int id2 = ni * n + nj;
                            unionSet(id1, id2, parent, rank);
                        }
                    }
                }
            }
        }

        // Count unique parents
        unordered_set<int> islands;
        for (int i = 0; i < m * n; i++) {
            if (parent[i] != -1) {
                islands.insert(findParent(i, parent));
            }
        }

        return islands.size();
    }
};
