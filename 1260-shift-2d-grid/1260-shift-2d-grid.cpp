class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        k = k % (m*n);
        while(k--){
            int prev = grid[m-1][n-1];
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    int curr = grid[i][j];
                    grid[i][j] = prev;
                    prev = curr;
                }
            }
        }
        return grid;
    }
};