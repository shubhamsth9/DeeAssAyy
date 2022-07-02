class Solution {
public:
    int maxArea(int h, int v, vector<int>& hCuts, vector<int>& vCuts) {
        int mod = 1e9 + 7;
        
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        
        int maxH = hCuts[0], maxV = vCuts[0];
        int n = hCuts.size(), m = vCuts.size();
        
        for(int i=1; i<n; i++)
            maxH = max(maxH, hCuts[i]-hCuts[i-1]);
        
        for(int i=1; i<m; i++)
            maxV = max(maxV, vCuts[i]-vCuts[i-1]);
       
        long long a = max(maxH, h-hCuts[n-1])%mod, b = max(maxV, v-vCuts[m-1])%mod;
        // long long res = ;
        return (int)((a * b)%mod);
    }
};