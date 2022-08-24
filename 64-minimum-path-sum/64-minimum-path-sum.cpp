class Solution {
public:
//     int fun(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid){
        
//         if(i == m-1 && j == n-1) return grid[i][j];
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int down = 100000, right = 100000;
//         if(i+1 < m) down = fun(i+1, j, m, n, dp, grid);
//         if(j+1 < n) right = fun(i, j+1, m, n, dp, grid);
        
//         return dp[i][j] = grid[i][j] + min(down, right);
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int left = INT_MAX, up = INT_MAX;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(left, up);
                }
            }
        }
        
        return dp[m-1][n-1];
        
    }
};