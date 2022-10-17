class Solution {
public:
    int dp[301][11];
    
    int dfs(vector<int>& job, int n, int i, int d){
        if(d == 0)
            return dp[i][d] = *max_element(job.begin()+i, job.end());
        
        if(dp[i][d] != -1) return dp[i][d];
        
        int mx_ele = INT_MIN, mn = INT_MAX;
        
        for(int j = i; j < n-d; j++){
            mx_ele = max(mx_ele, job[j]);
            mn = min(mn, mx_ele + dfs(job, n, j+1, d-1));
        }
        
        return dp[i][d] = mn;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        memset(dp, -1, sizeof(dp));
        return dfs(jobDifficulty, n, 0, d-1);
    }
};