class Solution {
public:
//     int f(int m, int n, vector<vector<int>> &dp){
        
//         if(m == 0 || n == 0) return 1;
//         if(m < 0 || n < 0) return 0;
//         if(dp[m][n] != -1) return dp[m][n];
        
//         dp[m-1][n] = f(m-1, n, dp);
//         dp[m][n-1] = f(m, n-1, dp);
        
//         return dp[m][n] = dp[m-1][n] + dp[m][n-1];
//     }
    
    int uniquePaths(int m, int n) {
        //vector<vector<int>> dp(m, vector<int>(n, 1));
//         vector<int> prev(n, 1);
        
//         for(int i=1; i<m; i++){
//             vector<int> curr(n, 1);
//             for(int j=1; j<n; j++){
//                 curr[j] = prev[j] + curr[j-1];
//             }
//             prev = curr;
//         }
//         return prev[n-1];
        int N = m+n-2, R = min(m-1, n-1);
        cout<<"N = "<<N<<" R = "<<R<<endl;
        double res = 1;
        for(int i=1; i<=R; i++){
            res = res * (N-R+i)/i;
        }
        return (int)res;
    }
};