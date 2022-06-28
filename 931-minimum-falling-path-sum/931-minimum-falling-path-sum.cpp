class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(j < 0 || j >= n) return INT_MAX;
        if(i == n-1) return mat[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int l = f(i+1, j-1, n, mat, dp);
        int d = f(i+1, j, n, mat, dp);
        int r = f(i+1, j+1, n, mat, dp);
        return dp[i][j] = mat[i][j] + min(l, min(d, r));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), res = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int i=0; i<n; i++){
            res = min(res, f(0, i, n, matrix, dp));
        }
        return res;
    }
};