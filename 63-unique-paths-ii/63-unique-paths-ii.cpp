class Solution {
public:
    // int f(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(m < 0 || n < 0 || grid[m][n] == 1) return 0;
    //     if(m == 0 && n == 0) return 1;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     return dp[m][n] = f(m-1, n, grid, dp) + f(m, n-1, grid, dp);
    // }
        
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int up = 0, left = 0;
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                } 
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};