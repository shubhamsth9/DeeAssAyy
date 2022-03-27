class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        int i=0, count=0;
        while(i<n-1){
            while((i < n-1) && (nums[i] == nums[i+1]) && (abs(i-count)%2 == 0)){
                count++;
                i++;
            }
            i++;
        }
        if((n-count)%2 == 0)
            return count;
        else
            return count+1;
    }
};