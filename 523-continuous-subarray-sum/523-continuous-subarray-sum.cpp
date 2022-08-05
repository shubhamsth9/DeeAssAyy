class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int n = nums.size(), sum = 0;
        umap[0] = -1;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(k != 0) sum = sum%k;
            if(i>0 && sum == 0) return true;
            if(umap.find(sum) != umap.end()){
                if(i - umap[sum] > 1) return true;
            }
            else umap[sum] = i;
        }
        return false;
    }
};