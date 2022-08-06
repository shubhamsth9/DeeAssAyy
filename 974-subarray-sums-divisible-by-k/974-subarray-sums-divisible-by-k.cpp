class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0, n=nums.size(), sum=0;
        unordered_map<int, int> umap;
        umap[0]++;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            
            int rem = sum%k;
            if(rem < 0) rem += k;
            //if(rem == 0) cnt++;
            if(umap.find(rem) != umap.end()){
                cnt += umap[rem];
            }
            umap[rem]++;
        }
        
        return cnt;
    }
};