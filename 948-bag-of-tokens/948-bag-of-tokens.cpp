class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        sort(tokens.begin(), tokens.end());
        
        int score = 0, n = tokens.size();
        int i=0, j=n-1, res=0;
        
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i];
                score++, i++;
                res = max(res, score);
            }
            else if(score > 0){
                power += tokens[j];
                score--, j--;
            }
            else return res;
        }
        return res;
    }
};