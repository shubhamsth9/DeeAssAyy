class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = m-1, top = 0, bottom = n-1, len = n*m;
        vector<int> res;
        
        while(res.size() < len){
            
            //left -> right
            for(int i=left; i<=right && res.size() < len; i++)
                res.push_back(matrix[top][i]);
            
            //top -> bottom
            for(int i=top+1; i<=bottom && res.size() < len; i++)
                res.push_back(matrix[i][right]);
            
            //right -> left
            for(int i=right-1; i>=left && res.size() < len; i--)
                res.push_back(matrix[bottom][i]);
            
            //bottom -> top
            for(int i=bottom-1; i>=top+1 && res.size() < len; i--)
                res.push_back(matrix[i][left]);
            
            left++, right--, top++, bottom--;
        }
        
        return res;
    }
};