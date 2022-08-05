class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, sum = 0;
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum == k) cnt++;
            if(umap.count(sum-k)) cnt += umap[sum-k];
            umap[sum]++;
        }
        return cnt;
    }
};