class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        sort(tokens.begin(), tokens.end());
        
        int score = 0, i=0, j=tokens.size()-1, res=0;
        
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                score++;
                res = max(res, score);
            }
            else if(score > 0){
                power += tokens[j--];
                score--;
            }
            else return res;
        }
        return res;
    }
};