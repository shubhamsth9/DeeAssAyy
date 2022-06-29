class Solution {
public:
    int f(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e7;
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        if(i == n-1){
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        
        int d[] = {-1, 0, 1};
        int res = INT_MIN;
        
        for(int p=0; p<3; p++){
            for(int q=0; q<3; q++){
                
                if(j1 == j2){
                    res = max(res, grid[i][j1] + f(i+1, j1+d[p], j2+d[q], n, m, grid, dp));
                }
                else
                    res = max(res, grid[i][j1] + grid[i][j2] + f(i+1, j1+d[p], j2+d[q], n, m, grid, dp));
            }
        }
        return dp[i][j1][j2] = res;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return f(0, 0, m-1, n, m, grid, dp);
    }
};