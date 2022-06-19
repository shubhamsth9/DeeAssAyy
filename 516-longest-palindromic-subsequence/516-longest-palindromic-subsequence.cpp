class Solution {
public:
    // int lps(int l, int r, string& s, vector<vector<int>>& memo){
    //     if(l == r) return 1;
    //     if(l > r) return 0;
    //     if(memo[l][r] != -1) return memo[l][r];
    //     if(s[l] == s[r]) memo[l][r] = 2 + lps(l+1, r-1, s, memo);
    //     else memo[l][r] = max(lps(l+1, r, s, memo), lps(l, r-1, s, memo));
    //     return memo[l][r];
    // }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=n-1; i>=0; i--){
            dp[i][i] = 1;
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};