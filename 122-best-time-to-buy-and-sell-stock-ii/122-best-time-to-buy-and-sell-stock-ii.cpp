class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int mini = prices[0], res = 0, n = prices.size();
        for(int i=1; i<n; i++){
            if(prices[i] < prices[i-1]){
                res += prices[i-1] - mini;
                mini = prices[i];
            }
        }
        if(prices[n-1] > mini) res += prices[n-1] - mini;
        return res;
    }
};