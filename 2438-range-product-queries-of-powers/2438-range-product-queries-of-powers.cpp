class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int m = 1000000007;
        vector<int> powers, res;
        for(int i=0; i<32; i++){
            if(n & (1 << i)) powers.push_back((1 << i));
        }
        
        for(int i=0; i<q.size(); i++){
            long temp = 1;
            for(int j = q[i][0]; j <= q[i][1]; j++){
                temp = (temp*powers[j])%m;
            }
            res.push_back(temp);
        }
        return res;
    }
};