class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int i = 0;
        while(i < nums.size()-2 && nums[i] >= nums[i+1] + nums[i+2]) i++;
        if(i >= nums.size()-2) return 0;
        return nums[i] + nums[i+1] + nums[i+2];
    }
};