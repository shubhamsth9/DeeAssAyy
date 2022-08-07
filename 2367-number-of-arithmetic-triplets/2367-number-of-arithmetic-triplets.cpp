class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int cnt = 0, n=nums.size();
        unordered_set<int> uset;
        
        for(int i=0; i<n; i++){
            if(uset.count(nums[i]-diff) && uset.count(nums[i]-2*diff)) cnt++;
            uset.insert(nums[i]);
        }
        
        return cnt;
    }
};