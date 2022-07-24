class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2, j =2, n = nums.size();
        if(n <= 2) return n;
        for(;j<n; j++){
            if(nums[i-2] != nums[j])
                nums[i++] = nums[j];
        }
        return i;
    }
};