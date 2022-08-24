class Solution {
public:
    int fun(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid){
        
        if(i == m-1 && j == n-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = 100000, right = 100000;
        if(i+1 < m) down = fun(i+1, j, m, n, dp, grid);
        if(j+1 < n) right = fun(i, j+1, m, n, dp, grid);
        
        return dp[i][j] = grid[i][j] + min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(0, 0, m, n, dp, grid);
        
    }
};