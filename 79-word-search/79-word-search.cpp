class Solution {
public:
    bool fun(int i, int j, int k, int len, int m, int n, vector<vector<char>>& board, string& word){
        if(k == len) return true;
        if(j+1 < n && board[i][j+1] == word[k]){
            char temp = board[i][j+1];
            board[i][j+1] = '0';
            if(fun(i, j+1, k+1, len, m, n, board, word)) return true;
            board[i][j+1] = temp;
        }
        if(j-1 >= 0 && board[i][j-1] == word[k]){
            char temp = board[i][j-1];
            board[i][j-1] = '0';
            if(fun(i, j-1, k+1, len, m, n, board, word)) return true;
            board[i][j-1] = temp;
        }
        if(i+1 < m && board[i+1][j] == word[k]){
            char temp = board[i+1][j];
            board[i+1][j] = '0';
            if(fun(i+1, j, k+1, len, m, n, board, word)) return true;
            board[i+1][j] = temp;
        }
        if(i-1 >= 0 && board[i-1][j] == word[k]){
            char temp = board[i-1][j];
            board[i-1][j] = '0';
            if(fun(i-1, j, k+1, len, m, n, board, word)) return true;
            board[i-1][j] = temp;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    char temp = board[i][j];
                    board[i][j] = '0';
                    if(fun(i, j, 1, len, m, n, board, word)) return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};