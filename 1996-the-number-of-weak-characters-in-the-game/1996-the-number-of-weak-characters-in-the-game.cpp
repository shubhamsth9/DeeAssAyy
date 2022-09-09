class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        sort(arr.begin(), arr.end(), [](const auto &a, const auto &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        int res = 0, n=arr.size(), mx =-1;
        for(int i=n-1; i>=0; i--){
            if(arr[i][1] < mx){
                res++;
            }
            else mx = arr[i][1];
        }
        return res;
    }
};