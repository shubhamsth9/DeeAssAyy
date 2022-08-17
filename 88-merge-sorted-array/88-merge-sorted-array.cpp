class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int i=m-1, j=n-1, k=n+m-1;
        while(i>=0 && j>=0){
            if(a[i] > b[j]){
                a[k] = a[i];
                i--;
            }
            else{
                a[k] = b[j];
                j--;
            }
            k--;
        }
        while(i>=0) a[k--] = a[i--];
        while(j>=0) a[k--] = b[j--];
    }
};