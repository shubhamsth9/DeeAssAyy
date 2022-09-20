class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n=height.size();
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int temp = st.top(); st.pop();
                if(st.empty()) break;
                int dist = i - st.top() - 1;
                int h = min(height[i], height[st.top()]) - height[temp];
                res += dist*h;
            }
            st.push(i);
        }
        
        return res;
    }
};