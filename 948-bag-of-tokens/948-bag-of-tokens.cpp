class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i=0, j=n-1, res=0;
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i];
                score++, i++;
                res = max(res, score);
            }
            else if(score >= 1){
                power += tokens[j];
                score--, j--;
            }
            else return res;
        }
        return res;
    }
};