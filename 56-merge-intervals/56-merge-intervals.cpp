class Solution {
public:
    static bool sortcol(const vector<int> &v1, const vector<int> &v2){
        return v1[0] < v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), sortcol);
        int i=1, j=0;
        int n= a.size();
        
        while(i<n){
            if(a[j][1] >= a[i][0]){
                a[j][0] = min(a[j][0], a[i][0]);
                a[j][1] = max(a[j][1], a[i][1]);
            }
            else{
                j++;
                a[j][0] = a[i][0], a[j][1] = a[i][1];
            }
            i++;
        }
        
        int k = n-j-1;
        while(k--){
            a.pop_back();
        }
        
        return a;
    }
};