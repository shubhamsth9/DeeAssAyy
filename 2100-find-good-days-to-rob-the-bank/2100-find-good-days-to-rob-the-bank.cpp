class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& a, int t) {
        int n = a.size();
        vector<int> res;
        vector<int> l(n, 0), r(n, 0);
        
        if(n <= (2*t)) return {};
        
        for(int i=1; i<n; i++){
            if(a[i] <= a[i-1]) l[i] = 1 + l[i-1];
            if(a[n-i-1] <= a[n-i]) r[n-i-1] = 1 + r[n-i];
        }
        
        for(int k = t; k<(n-t); k++)
            if(l[k] >= t && r[k] >= t) res.push_back(k);
        
        return res;
    }
};