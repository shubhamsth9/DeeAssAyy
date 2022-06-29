class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }
        
        if(dp[i][j] != INT_MIN) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=0; k<n; k++){
            if(k != j)
                mini = min(mini, grid[i][j] + f(i+1, k, n, grid, dp));
        }
        return dp[i][j] = mini;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), res = INT_MAX;
        if(n == 1) return grid[0][0];
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        
        for(int j=0; j<n; j++){
            res = min(res, f(0, j, n, grid, dp));
        }
        
        return res;
    }
};