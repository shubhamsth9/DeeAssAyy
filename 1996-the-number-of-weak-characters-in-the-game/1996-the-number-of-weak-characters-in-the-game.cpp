class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0]; 
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), comp);
        int res = 0, n=arr.size(), mx = arr[n-1][1];
        for(int i=n-2; i>=0; i--){
            if(arr[i][1] < mx){
                res++;
            }
            else mx = arr[i][1];
        }
        return res;
    }
};