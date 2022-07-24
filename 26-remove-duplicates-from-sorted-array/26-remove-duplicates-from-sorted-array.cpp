class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1;
        int n = nums.size();
        while(j<n){
            while(j<n && nums[j] == nums[i]) j++;
            if(j<n){
                swap(nums[i+1], nums[j]);
                i++, j++;
            }
        }
        return i+1;
    }
};