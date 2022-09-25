class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0, res = 0, cnt = 0;
        
        for(int num:nums)
            mx = max(num, mx);
        
        for(int num:nums){
            if(num == mx) cnt++;
            else cnt = 0;
            res = max(res, cnt);
        }
        return res;
    }
};