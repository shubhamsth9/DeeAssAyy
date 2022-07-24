class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        
      for (int i =0; i<n; i++)
      {
          if(nums[i] != nums[k])
          {
              k++;
              nums [k] = nums[i];
          }
      }
        return k+1;
    }
};