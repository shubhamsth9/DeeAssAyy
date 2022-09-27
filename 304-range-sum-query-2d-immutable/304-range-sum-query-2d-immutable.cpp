class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& matrix) {
        a = matrix;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 && j== 0) 
                    continue;
                if(i == 0)
                    a[i][j] += a[i][j-1];
                else if(j == 0) 
                    a[i][j] += a[i-1][j];
                else
                    a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        if(r1 == 0 && c1 == 0) 
            return a[r2][c2];
        
        if(r1 == 0)
            return a[r2][c2] - a[r2][c1-1];
        
        if(c1 == 0)
            return a[r2][c2] - a[r1-1][c2];
        
        return a[r2][c2] - a[r1-1][c2] - a[r2][c1-1] + a[r1-1][c1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */