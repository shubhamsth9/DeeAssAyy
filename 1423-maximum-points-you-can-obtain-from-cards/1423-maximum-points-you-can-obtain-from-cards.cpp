class Solution {
public: 
    int maxScore(vector<int>& cardPoints, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int i = 0, sum = 0;
        
        while(i<k) {
            sum += cardPoints[i];
            i++;
        }
        i--;
        int res = sum, j = cardPoints.size()-1;
        
        while(i+1 != 0){
            sum = sum - cardPoints[i] + cardPoints[j];
            res = max(res, sum);
            i--, j--;
        }
        
        return res;
    }
};