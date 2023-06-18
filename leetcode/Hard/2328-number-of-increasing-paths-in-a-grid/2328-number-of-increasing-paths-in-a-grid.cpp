class Solution {
private:
    int m, n;
    int dx[4] = {0, 0, -1, +1};
    int dy[4] = {-1, +1, 0, 0};
    vector<vector<int>> dp;
    
    int countOfPathsAtNextCell(int x, int y, vector<vector<int>> &grid) {
        int ret = 0;
        if (dp[x][y] != 0) {
            return dp[x][y];
        } else {
            ret += 1; // currentNode;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (0 <= nx && nx < m && 0 <= ny && ny < n) { // check range
                    if (grid[x][y] < grid[nx][ny]) { // check strictly increasing
                        ret += countOfPathsAtNextCell(nx, ny, grid) % 1000000007;
                    }
                }
            }
        }
        dp[x][y] = ret % 1000000007;
        return ret;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        
        int answer = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                answer += countOfPathsAtNextCell(i, j, grid);
                answer %= 1000000007;
            }
        }
        return answer;
    }
};