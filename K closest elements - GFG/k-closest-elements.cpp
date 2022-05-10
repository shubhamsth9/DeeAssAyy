// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> res;
        int l=0, h=n-1, mid;
        while(l <= h){
            mid = (h+l)/2;
            if(arr[mid] == x) break;
            else if(arr[mid] > x) h = mid-1;
            else l = mid+1;
        }
        
        int i=h, j=l;
        if(arr[mid] == x) i=mid-1, j=mid+1;
        
        while(k--){
            if(i<0){
                res.push_back(arr[j]);
                j++;
            }
            else if(j>=n) {
                res.push_back(arr[i]);
                i--;
            }
            else if(abs(arr[i] - x) < abs(arr[j] - x)){
                res.push_back(arr[i]);
                i--;
            }
            else if(abs(arr[i] - x) >= abs(arr[j] - x)){
                res.push_back(arr[j]);
                j++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends