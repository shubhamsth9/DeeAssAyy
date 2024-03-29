class Solution {
public:
    int rev(int num)
    {
        int x = 0;
        while (num > 0) {
            x = x * 10 + num % 10;
            num = num / 10;
        }
        return x;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        for(auto i:nums){
            uset.insert(rev(i));
        }
        return uset.size();
    }
};