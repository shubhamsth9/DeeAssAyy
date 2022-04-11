class Solution {
public:
    static bool sortcol(const vector<int> &v1, const vector<int> &v2){
        return v1[0] < v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), sortcol);
        int i=0, j=0;
        int n= a.size();
        vector<vector<int>> res;
        
        while(i<n){
            int start = a[i][0], end = a[i][1];
            int j = i+1;
            while(j<n && a[j][0] <= end){
                end = max(end, a[j][1]);
                j++;
            }
            res.push_back({start, end});
            i = j;
        }
        return res;
    }
};