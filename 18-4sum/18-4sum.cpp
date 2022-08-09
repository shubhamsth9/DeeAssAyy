class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        
        for(int i=0; i<n-3; i++){
            long int target2 = target - nums[i];
            for(int j=i+1; j<n-2; j++){
                long int temp = target2 - nums[j];
                int p = j+1, q = n-1;
                while(p < q) {
                    long int sum = nums[p] + nums[q];
                    if(sum < temp) p++;
                    else if(sum > temp) q--;
                    else {
                        int pt = nums[p], qt = nums[q];
                        res.push_back({nums[i], nums[j], nums[p], nums[q]});
                        while(p<q && nums[p] == pt) p++;
                        while(p<q && nums[q] == qt) q--;
                    }
                }
                while(j<n-2 && nums[j] == nums[j+1]) j++;
            }
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};