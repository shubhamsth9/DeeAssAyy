class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slo = nums[0], fast = nums[0];
        do{
            slo = nums[slo];
            fast = nums[nums[fast]];
        }while(fast != slo);
        
        slo = nums[0];
        
        while( slo != fast){
            slo = nums[slo];
            fast = nums[fast];
        }
        return slo;
    }
};