class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        vector<int> left(n+1, 1), right(n+1, 1);
        
        for(int i=1; i<n; i++)
            if(nums[i-1] >= nums[i])
                left[i] = left[i-1]+1;
        
        for(int i=n-2; i>=0; i--)
            if(nums[i] <= nums[i+1])
                right[i] = right[i+1]+1;
                
        for(int i=1; i<n-1; i++){
            if(left[i-1] >= k && right[i+1] >= k) res.push_back(i);
        }
        
        return res;
    }
};