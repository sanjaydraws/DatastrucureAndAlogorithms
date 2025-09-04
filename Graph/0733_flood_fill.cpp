//https://leetcode.com/problems/flood-fill/description/
//733. Flood Fill

class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor) {
        int m = image.size(), n = image[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n || image[x][y] != oldColor) return;

        image[x][y] = newColor;
        dfs(image, x+1, y, oldColor, newColor);
        dfs(image, x-1, y, oldColor, newColor);
        dfs(image, x, y+1, oldColor, newColor);
        dfs(image, x, y-1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && image[nx][ny] == oldColor) {
                    image[nx][ny] = newColor;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};
