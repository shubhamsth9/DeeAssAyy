class Solution {
public:
    int lps(int l, int r, string& s, vector<vector<int>>& memo){
        if(l == r) return 1;
        if(l > r) return 0;
        if(memo[l][r] != -1) return memo[l][r];
        if(s[l] == s[r]) memo[l][r] = 2 + lps(l+1, r-1, s, memo);
        else memo[l][r] = max(lps(l+1, r, s, memo), lps(l, r-1, s, memo));
        return memo[l][r];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return lps(0, n-1, s, memo);
    }
};