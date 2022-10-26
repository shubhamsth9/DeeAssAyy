class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap = {{0, 0}};
        int sum = 0, n = nums.size();
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(umap.count(sum%k) == 0) umap[sum%k] = i+1;
            else if(umap[sum%k] < i) return true;
        }
        return false;
    }
};