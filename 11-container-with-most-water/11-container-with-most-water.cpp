class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int res = 0, i = 0, j = height.size()-1;
        
        while(i < j) {
            int h = min(height[i], height[j]);
            res = max(res, (j-i)*h);
            while(i<j && height[i] <= h) i++;
            while(i<j && height[j] <= h) j--;
        }
        
        return res;
    }
};