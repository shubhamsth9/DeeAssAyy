class Solution {
public:
//     int fun(int i, int j, int k, vector<int>& cardPoints){
//         if(k <= 0) return 0;
//         int l = cardPoints[i] + fun(i+1, j, k-1, cardPoints);
//         int r = cardPoints[j] + fun(i, j-1, k-1, cardPoints);
//         return max(l, r);
//     }
        
    int maxScore(vector<int>& cardPoints, int k) {
        
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
        
        // return fun(0, cardPoints.size()-1, k, cardPoints);
    }
};