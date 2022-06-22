class Solution {
public:
    int rob(vector<int>& nums) {
        int temp1, temp2;
        temp1 = temp2 = nums[0];
        if(nums.size()>1) temp1 = max(nums[1], nums[0]);
        for(int i=2; i<nums.size(); i++){
            int curr = max(temp1, nums[i]+temp2);
            temp2 = temp1;
            temp1 = curr;
        }
        return temp1;
    }
};