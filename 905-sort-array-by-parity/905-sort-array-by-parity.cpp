class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[i]%2 == 0) i++;
            else
                while(i<j){
                    if(nums[j]%2 == 0 && nums[i]%2 == 1){
                        swap(nums[i], nums[j]);
                        j--; break;
                    }   
                    j--;
                }
        }
        return nums;
    }
};