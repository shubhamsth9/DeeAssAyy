class Solution {
public:
    int f(vector<int>& nums, int l, int h){
        int curr = 0, prev=0;
        for(int i=l; i<=h; i++){
            int temp = max(nums[i]+prev, curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        return max(f(nums, 0, n-2), f(nums, 1, n-1));
    }
};