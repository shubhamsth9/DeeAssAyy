
class Solution {
public:
    int helper(int l, int r, vector<int>& nums, vector<int>& mul, vector<vector<int>>& dp){
        int n = nums.size();
        if(((n-1)-(r-l)) == mul.size()) return 0;
        if(dp[(n-1)-(r-l)][l] != INT_MIN) return dp[(n-1)-(r-l)][l];
        
        int left = nums[l]*mul[(n-1)-(r-l)] + helper(l+1, r, nums, mul, dp);
        int right = nums[r]*mul[(n-1)-(r-l)] + helper(l, r-1, nums, mul, dp);
        
        return dp[(n-1)-(r-l)][l] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n=nums.size(), m = mul.size();
        vector<vector<int>> dp(1001, vector<int>(1001, INT_MIN));
        return helper(0, n-1, nums, mul, dp);
    }
};