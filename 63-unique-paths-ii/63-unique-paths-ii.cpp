class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i > m || j > n || grid[i][j] == 1) return 0;
        if(i == m && j == n) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i+1, j, m, n, grid, dp) + f(i, j+1, m, n, grid, dp);
    }
        
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m-1, n-1, grid, dp);
    }
};