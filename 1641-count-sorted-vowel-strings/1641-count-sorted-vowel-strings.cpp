class Solution {
public:
    
    int countVowelStrings(int n) {
        int res = 0;
        vector<int> dp(5, 1);
        
        while(--n){
            for(int i=3; i>=0; i--)
                dp[i] += dp[i+1];
        }
        
        for(auto i:dp)
            res += i;
        
        return res;
    }
};