class Solution {
public:
    bool fun(int i, int n, int target, vector<vector<int>> &dp, vector<int>&nums){
        if(i >= n || target < 0) return false;
        if(target == 0) return true;
        if(dp[i][target] != -1) return dp[i][target];
        bool take = fun(i+1, n, target-nums[i], dp, nums);
        bool nottake = fun(i+1, n, target, dp, nums);
        return dp[i][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto it:nums) sum+= it;
        if(sum%2) return false;
        sum = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return fun(0, n, sum, dp, nums);
    }
};