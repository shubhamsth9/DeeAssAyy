class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(nullptr);
        
        if(mat == target) return true;
        int n = target.size();
        for(int i=0; i<3; i++){
            for(int p=0; p<n; p++){
                for(int q=p; q<n; q++) swap(mat[p][q], mat[q][p]);
            }
            for(int p=0; p<n; p++){
                reverse(mat[p].begin(), mat[p].end());
            }
            if(mat == target) return true;
        }
        return false; 
    }
};