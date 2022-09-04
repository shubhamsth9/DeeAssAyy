class Solution {
public:
    void util(int i, int n, int k, vector<int>&res){
        if(n == 0){
            res.push_back(i);
            return;
        }
        if(i%10 + k <= 9) util(i*10 + ((i%10) + k), n-1, k, res);
        if(k != 0 && i%10 - k >= 0) util(i*10 + ((i%10) - k), n-1, k, res);
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i=1; i<=9; i++){
            util(i, n-1, k, res);
        }
        return res;
    }
};