class Solution {
public:
//     int f(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
//         if(m == 0 && n == 0) return grid[0][0];
        
//         if(dp[m][n] != -1) return dp[m][n];
        
//         int up = INT_MAX, left = INT_MAX;
        
//         if(m-1 >= 0) up = grid[m][n] + f(m-1, n, grid, dp);
//         if(n-1 >= 0) left = grid[m][n] + f(m, n-1, grid, dp);
        
//         return dp[m][n] = min(up, left);
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size();
        vector<int> prev(n, INT_MAX);
        
        for(int i=0; i<m; i++){
            vector<int> curr(n, INT_MAX);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) curr[j] = grid[i][j];
                else {
                    
                    int up = INT_MAX, left = INT_MAX;
                    
                    if(i > 0) up = grid[i][j] + prev[j];
                    
                    if(j > 0) left = grid[i][j] + curr[j-1];
                    
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        
        return prev[n-1];
        
    }
};