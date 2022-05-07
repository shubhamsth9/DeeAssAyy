class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int x = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(nums[i] < x) return true;
            while(!st.empty() && nums[i] > st.top()){
                x = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        
        return false;
    }
};