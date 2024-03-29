class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int cnt = 1, ele = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == ele) cnt++;
            else if(nums[i] != ele) cnt--;
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }
        }
        return ele;
    }
};