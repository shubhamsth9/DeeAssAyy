class Solution {
public:
//     bool util(int i, vector<int>& memo, vector<int>& nums){
//         if(i == nums.size()-1 ) return true;
        
//         if(memo[i] != -1) return memo[i];
        
//         for(int k = 1; k <= nums[i]; k++){
//             if(util(i+k, memo, nums))
//                 return memo[i] = true;
//         }
//         return memo[i] = false;
//     }
    
    bool canJump(vector<int>& nums) {
        
        int reach = 0, n = nums.size();
        
        for(int i=0; i<n; i++){
            if(i > reach) return false;
            reach = max(reach, i+nums[i]);
            if(reach >= n-1) return true;
        }
        
        return true;
        // vector<int> memo(nums.size(), -1);
        // return util(0, memo, nums);
    }
};