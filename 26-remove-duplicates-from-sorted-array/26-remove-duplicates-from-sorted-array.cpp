class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] != nums[cnt])
                nums[++cnt] = nums[i];
        }
        return cnt+1;
    }
};