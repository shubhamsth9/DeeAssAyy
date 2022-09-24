class Solution {
public:
    bool dfs(int maxint, int total, int chosen, vector<int>& dp){
        if(total <= 0) return false;
        
        if(dp[chosen] != -1) return dp[chosen];
        
        for(int i=1; i<=maxint; i++){
            if((chosen & (1<<i))) continue;
            chosen = (chosen | (1<<i));
            if(!dfs(maxint, total-i, chosen, dp)){
                chosen = (chosen ^ (1<<i));
                return dp[chosen] = 1;
            }
            chosen = (chosen ^ (1<<i));
        }
        
        return dp[chosen] = 0;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        if((maxChoosableInteger*(maxChoosableInteger+1))/2 < desiredTotal) return false;
        int x = (1<<21);
        vector<int> dp(x, -1);
        return dfs(maxChoosableInteger, desiredTotal, 0, dp);
    }
};