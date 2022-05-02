class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1, k=0;
        while(k<j){
            if(nums[k]%2 == 0)
                swap(nums[i++], nums[k++]);
            else
                swap(nums[j--], nums[k]);
        }
        return nums;
    }
};