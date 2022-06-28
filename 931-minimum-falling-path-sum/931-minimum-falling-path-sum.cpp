class Solution {
public:
//     int f(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
//         if(j < 0 || j >= n) return INT_MAX;
//         if(i == n-1) return mat[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int l = f(i+1, j-1, n, mat, dp);
//         int d = f(i+1, j, n, mat, dp);
//         int r = f(i+1, j+1, n, mat, dp);
//         return dp[i][j] = mat[i][j] + min(l, min(d, r));
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), res = INT_MAX;
        vector<int> dp(n);
        
        for(int j = 0; j < n ; j++) dp[j] = matrix[n-1][j];
        
        for(int i=n-2; i>=0; i--){
            vector<int> curr(n);
            for(int j = 0; j<n; j++){
                int l = INT_MAX, d = dp[j], r = INT_MAX;
                if(j-1 >= 0) l = dp[j-1];
                if(j + 1 <n) r = dp[j+1];
                curr[j] = matrix[i][j] + min(l, min(d, r));
            }
            dp = curr;
        }
        
        for(int j=0; j<n; j++) res = min(res, dp[j]);
        
        return res;
        
        // for(int i=0; i<n; i++){
        //     res = min(res, f(0, i, n, matrix, dp));
        // }
        // return res;
    }
};