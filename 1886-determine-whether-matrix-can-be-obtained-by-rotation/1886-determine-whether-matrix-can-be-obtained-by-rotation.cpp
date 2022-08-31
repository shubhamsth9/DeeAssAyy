class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        if(mat == target) return true;
        
        bool c[3] = {true, true, true};
        int n = target.size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[n-j-1][i]) c[0] = false;
                if(mat[i][j] != target[n-i-1][n-j-1]) c[1] = false;
                if(mat[i][j] != target[j][n-i-1]) c[2] = false;
            }
        }
        return c[0] || c[1] || c[2];
    }
};