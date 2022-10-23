class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int n = nums.size();
        vector<bool> map(n+1, 0);
        for(int i = 0; i<n; i++){
            if(map[nums[i]] == true){
                res[0] = nums[i];
            }
            map[nums[i]] = true;
        }
        for(int i = 1; i<=n; i++){
            if(map[i] == false) res[1] = i;
        }
        return res;
    }
};