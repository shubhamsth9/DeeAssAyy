class Solution {
public:
    bool util(int i, vector<int>& memo, vector<int>& nums){
        if(i == nums.size()-1 ) return true;
        
        if(memo[i] != -1) return memo[i];
        
        for(int k = 1; k <= nums[i]; k++){
            if(util(i+k, memo, nums))
                return memo[i] = true;
        }
        return memo[i] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return util(0, memo, nums);
    }
};