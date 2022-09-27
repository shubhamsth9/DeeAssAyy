class NumArray {
public:
    vector<int> a;
    NumArray(vector<int>& nums) {
        for(auto it:nums) a.push_back(it);
    }
    
    int sumRange(int left, int right) {
        int res = 0;
        for(int i=left; i<=right; i++) res += a[i];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */