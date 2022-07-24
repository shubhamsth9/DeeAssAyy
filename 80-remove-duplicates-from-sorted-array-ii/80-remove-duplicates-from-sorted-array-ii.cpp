class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        int i = 0;
        for(auto it : mp){
            nums[i++] = it.first;
            if(it.second >= 2) nums[i++] = it.first;
        }
        return i;
    }
};