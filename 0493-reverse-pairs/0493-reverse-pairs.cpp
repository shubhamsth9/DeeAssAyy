class Solution {
    int count;
public:
    void merge(vector<int> &nums, int l, int mid, int r){
        int i = l, j = mid+1;
        while(i <= mid && j <= r){
            if((long)nums[i] > (long)2*nums[j]){
                count += (mid - i + 1);
                j++;
            }
            else i++;
        }
        if(l == 0 && r == nums.size()-1) return;
        sort(nums.begin()+l, nums.begin()+r+1);
    }
    
    void mergesort(vector<int> &nums, int l, int r){
        if(l >= r) return;
        int mid = (l+r)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
    
    int reversePairs(vector<int>& nums) {
        count = 0;
        mergesort(nums, 0, nums.size()-1);
        return count;
    }
};