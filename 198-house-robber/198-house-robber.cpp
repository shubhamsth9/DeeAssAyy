class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), temp1, temp2;
        temp1 = temp2 = nums[0];
        if(n>1) temp1 = max(nums[1], nums[0]);
        for(int i=2; i<n; i++){
            int curr = max(temp1, nums[i]+temp2);
            temp2 = temp1;
            temp1 = curr;
        }
        return temp1;
    }
};