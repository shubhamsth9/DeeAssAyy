class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count=0;
                for(int a=max(i-1, 0); a<min(i+2,n); a++){
                    for(int b=max(j-1, 0); b<min(j+2, m); b++){
                        if(board[a][b] & 1) count++;
                    }
                }
                if(count == 3 || count-board[i][j] == 3)
                    board[i][j] |= 2;
                
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] >>= 1;
            }
        }
    }
};