class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1;
        int n = nums.size();
        while(j<n){
            while(j<n && nums[j] == nums[i]) j++;
            if(j<n){
                nums[++i] = nums[j++];
            }
        }
        return i+1;
    }
};