class Solution {
public:
    long long gridGame(vector<vector<int>>& temp) {
        int n = temp[0].size();
        
        vector<vector<long long>> grid(2, vector<long long>(n, 0));
        grid[0][0] = temp[0][0];
        grid[1][n-1] = temp[1][n-1];
        
        for(int j = 1; j < n; j++){
            grid[0][j] += grid[0][j-1] + temp[0][j];
            grid[1][n-j-1] += grid[1][n-j] + temp[1][n-j-1];
        }
        long long res = LLONG_MAX;
        
        for(int i=0; i<n; i++){
            long long val = max(grid[0][n-1] - grid[0][i], grid[1][0] - grid[1][i]);
            
            res = min(res, val);
        }
        
        return res;
    }
};