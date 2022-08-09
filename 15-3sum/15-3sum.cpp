class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i=0; i<n-2; i++){
            
            int target = -nums[i];
            int low = i+1, high = n-1;
            
            if(target < 0) break;
            
            while(low < high){
                if(nums[low] + nums[high] < target) low++;
                else if(nums[low] + nums[high] > target) high--;
                else{
                    vector<int> trip = {nums[i], nums[low], nums[high]};
                    res.push_back(trip);
                    while(low < high && nums[low] == trip[1]) low++;
                    while(low < high && nums[high] == trip[2]) high--;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};