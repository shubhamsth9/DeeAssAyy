class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int reach = 0, n = nums.size();
        
        for(int i=0; i<n; i++){
            if(i > reach) return false;
            reach = max(reach, i+nums[i]);
            if(reach >= n-1) return true;
        }
        
        return true;
    }
};