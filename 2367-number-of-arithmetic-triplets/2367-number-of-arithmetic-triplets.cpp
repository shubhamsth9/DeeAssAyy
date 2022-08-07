class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int cnt = 0, n=nums.size();
        unordered_set<int> uset(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++){
            int temp1 = nums[i]+diff, temp2 = (2*diff) + nums[i];
            if(uset.find(temp1) != uset.end() && uset.find(temp2) != uset.end()) cnt++;
        }
        return cnt;
    }
};