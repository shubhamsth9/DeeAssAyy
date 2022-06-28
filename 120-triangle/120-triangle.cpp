class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& tri, vector<vector<int>> &dp){
    //     if(i == tri.size()-1) return dp[i][j] = tri[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return dp[i][j] = tri[i][j] + min(f(i+1, j, tri, dp), f(i+1, j+1, tri, dp));
    // }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        
        for(int j=n-1; j>=0; j--) dp[j] = triangle[n-1][j];
        
        for(int i = n-2; i >= 0 ; i--){
            vector<int> curr(n);
            for(int j=i; j>=0; j--){
                curr[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
            dp = curr;
        }
        
        return dp[0];
        //return f(0, 0, triangle, dp);
    }
};