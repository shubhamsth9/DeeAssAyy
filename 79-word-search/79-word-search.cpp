class Solution {
public:
    bool fun(int i, int j, int k, int len, vector<vector<char>>& board, string& word){
        
        if(k == len) return true;
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || 
          board[i][j] != word[k]) return false;
        
        char temp = board[i][j];
        board[i][j] = '0';
        
        bool res = fun(i-1, j, k+1, len, board, word) || fun(i+1, j, k+1, len, board, word) || fun(i, j-1, k+1, len, board, word) || fun(i, j+1, k+1, len, board, word);
        
        board[i][j] = temp;
        
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(fun(i, j, 0, len, board, word))
                    return true;
            }
        }
        return false;
    }
};