class Solution {
public:
    int check(int i, int j, int m, int n, vector<vector<int>>& board){
        int cnt = 0;
        
        for(int I=max(0, i-1); I<min(m, i+2); I++){
            for(int J=max(0, j-1); J<min(n, j+2); J++){
                if(I == i && J == j) continue;
                if(board[I][J] == 1 || board[I][J] == 3) cnt++;
            }
        }
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int cnt = check(i, j, m, n, board);
                if(board[i][j] == 0 && cnt == 3){
                    board[i][j] = 2;
                }
                else if(board[i][j] == 1){
                    if(cnt < 2 || cnt > 3) board[i][j] = 3;
                }
                
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};