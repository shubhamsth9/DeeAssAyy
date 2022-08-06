class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> freq(k, 0);
        freq[0] = 1;
        int cnt = 0, n = nums.size(), sum=0;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = sum%k;
            if(rem < 0) rem += k;
            cnt += freq[rem];
            freq[rem]++;
        }
        return cnt;
        
//         int cnt = 0, n=nums.size(), sum=0;
//         unordered_map<int, int> umap;
//         umap[0]++;
        
//         for(int i=0; i<n; i++){
//             sum += nums[i];
            
//             int rem = sum%k;
//             if(rem < 0) rem += k;
//             //if(rem == 0) cnt++;
//             if(umap.find(rem) != umap.end()){
//                 cnt += umap[rem];
//             }
//             umap[rem]++;
//         }
        
//         return cnt;
    }
};