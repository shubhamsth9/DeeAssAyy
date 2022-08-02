class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0, n=nums.size();
        while(j<n){
            while(i<n && nums[i] != 0){
                i++;
            }
            j = i;
            while(j<n && nums[j] == 0){
                j++;
            }
            if(j<n){
                if(i >= n) break;
                swap(nums[i], nums[j]);
                i++; j++;
            }
        }
    }
};