class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size(), cnt = 1;
        vector<bool> left(n, false), right(n, false);
        
        for(int i=1; i<n; i++){
            if(nums[i] <= nums[i-1]){
                cnt++;
                if(cnt >= k) left[i] = true;
            }
            else cnt = 1;
        }
        cnt = 1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] <= nums[i+1]){
                cnt++;
                if(cnt >= k) right[i] = true;
            }
            else cnt = 1;
        }
        vector<int> res;
        
        if(k == 1){
            for(int i=1; i<n-1; i++){
                res.push_back(i);
            }
            return res;
        }
        
        for(int i=1; i<n-1; i++){
            if(left[i-1] && right[i+1]) res.push_back(i);
        }
        
        return res;
    }
};