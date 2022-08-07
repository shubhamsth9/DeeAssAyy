class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int cnt = 0, n=nums.size();
        unordered_set<int> uset;
        
        for(auto it:nums){
            if(uset.count(it - diff) && uset.count(it - 2*diff)) cnt++;
            uset.insert(it);
        }
        
        return cnt;
    }
};