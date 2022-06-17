
class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.length(), n=s2.length();
        
        short dp[1001][1001] = {{0}};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i+1][j+1] = s1[i] == s2[j] ? 1 + dp[i][j] : max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[m][n];
    }
};