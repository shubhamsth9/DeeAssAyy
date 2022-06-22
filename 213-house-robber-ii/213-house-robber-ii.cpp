class Solution {
public:
    int f(vector<int>& nums){
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
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        vector<int> copy;
        for(int i=1; i<n; i++){
            copy.push_back(nums[i]);
        }
        nums.pop_back();
        return max(f(nums), f(copy));
    }
};