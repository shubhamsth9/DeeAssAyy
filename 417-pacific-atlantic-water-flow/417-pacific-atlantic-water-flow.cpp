class Solution {
public:
    vector<vector<bool>> pac, atl;
    
    void setTrue(int i, int j, int m, int n, vector<vector<bool>> &vis, vector<vector<int>>& h){
        if(vis[i][j]) return;
        vis[i][j] = true;
        
        if(i-1 >= 0 && h[i-1][j] >= h[i][j]) setTrue(i-1, j, m, n, vis, h);
        if(i+1 < m && h[i+1][j] >= h[i][j]) setTrue(i+1, j, m, n, vis, h);
        if(j-1 >= 0 && h[i][j-1] >= h[i][j]) setTrue(i, j-1, m, n, vis, h);
        if(j+1 < n && h[i][j+1] >= h[i][j]) setTrue(i, j+1, m, n, vis, h);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> res;
        int m = h.size(), n = h[0].size();
        pac = atl = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) setTrue(i, 0, m, n, pac, h), setTrue(i, n-1, m, n, atl, h);
        for(int i=0; i<n; i++) setTrue(0, i, m, n, pac, h), setTrue(m-1, i, m, n, atl, h);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};