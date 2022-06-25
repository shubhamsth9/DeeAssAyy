class Solution {
public:
    int f(int m, int n, vector<vector<int>> &dp){
        
        if(m == 0 || n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        
        dp[m-1][n] = f(m-1, n, dp);
        dp[m][n-1] = f(m, n-1, dp);
        
        return dp[m][n] = dp[m-1][n] + dp[m][n-1];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp);
    }
};