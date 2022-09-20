class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int i = 0, res = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = dp[i+1][j+1] + 1;
                    if(res<dp[i][j]) res = dp[i][j];
                }
            }
        }
        return res;
    }
};