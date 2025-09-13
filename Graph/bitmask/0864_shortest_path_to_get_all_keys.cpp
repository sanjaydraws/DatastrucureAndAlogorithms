// https://leetcode.com/problems/shortest-path-to-get-all-keys/description/

//864. Shortest Path to Get All Keys
//Graph (BFS + Bitmask)
// Approach: Multi-state BFS with Bitmask (for shortest path with keys/locks)"

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int allKeys = 0, sr, sc;

        // STEP 1: Count total keys + Find start position
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ; j++){
                char c = grid[i][j];
                if(c == '@') sr = i, sc = j; // starting row & col
                if(c >= 'a' && c <= 'f'){    
                    // mark this key in bitmask (1 << (c - 'a'))
                    allKeys |= (1 << (c - 'a'));
                }
            }
        }

        // STEP 2: BFS Setup → queue stores (x,y,mask)
        queue<tuple<int,int,int>> q;
        // 3D dist array → dist[row][col][mask] = min steps
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(64, -1)));

        // Start push into queue with mask=0 (no keys collected yet)
        q.push({sr, sc, 0});
        dist[sr][sc][0] = 0;

        // Directions (UP, DOWN, LEFT, RIGHT)
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // STEP 3: BFS Loop
        while(!q.empty()){
            auto [x, y, mask] = q.front(); q.pop();
            int d = dist[x][y][mask];  // current distance

            // STEP 4: If all keys collected → return steps
            if(mask == allKeys) return d;

            // STEP 5: Explore neighbors
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nMask = mask;

                // boundary check
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                char c = grid[nx][ny];

                // wall check
                if(c == '#') continue;

                // lock check (A-F)
                if(c >= 'A' && c <= 'F'){
                    // if we don’t have its key, skip
                    if(!(mask & (1 << (c - 'A')))) continue;
                }

                // key check (a-f)
                if(c >= 'a' && c <= 'f'){
                    // add this key into mask
                    nMask |= (1 << (c - 'a'));
                }

                // If not visited this state → push into queue
                if(dist[nx][ny][nMask] == -1){
                    dist[nx][ny][nMask] = d + 1;
                    q.push({nx, ny, nMask});
                }
            }
        }

        // STEP 6: If BFS ends without collecting all keys
        return -1;
    }
};

/*
TIME COMPLEXITY:
---------------
At most we visit each (row, col, mask) once.
- Grid size = m*n
- Key mask states = 2^K  (K ≤ 6, so max 64)
Total states = m * n * (2^K)

Each state processes 4 directions → O(4 * m * n * 2^K) ≈ O(m * n * 2^K)

SPACE COMPLEXITY:
----------------
- dist array = O(m * n * 2^K)
- queue = O(m * n * 2^K) in worst case

So, S.C. = O(m * n * 2^K)
*/
