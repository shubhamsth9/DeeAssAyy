class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n=height.size();
        vector<int> lmax(n,0), rmax(n,0);
        
        for(int i=1; i<n; i++){
            lmax[i] = max(lmax[i-1], height[i-1]);
            rmax[n-i-1] = max(rmax[n-i], height[n-i]);
        }
        
        for(int i=1; i<n-1; i++){
            int tmp = min(lmax[i], rmax[i])-height[i];
            if(tmp > 0) res += tmp;
        }
        
        return res;
    }
};