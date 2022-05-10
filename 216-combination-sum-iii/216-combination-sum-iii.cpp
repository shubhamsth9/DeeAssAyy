class Solution {
public:
    vector<vector<int>> res;
    
    void util(int k, int sum, int idx, vector<int> temp){
        if(k == 0){
            if(sum == 0)
                res.push_back(temp);
            return;
        }
        for(int i = idx+1; i<=9; i++){
            if(sum < 0) break;
            temp.push_back(i);
            util(k-1, sum-i, i, temp);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n == 1 && k > 1) return {};
        vector<int> temp;
        util(k, n, 0, temp);
        return res;
    }
};