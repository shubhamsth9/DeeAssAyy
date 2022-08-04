class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int res = 0, n = prices.size();
        for(int i=1; i<n; i++){
            int diff = prices[i] - prices[i-1];
            if(diff > 0){
                res += diff;
            }
        }
        return res;
    }
};