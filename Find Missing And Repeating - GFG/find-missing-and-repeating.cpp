// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(int *arr, int n) {
        int a=0, b=0;
        vector<int> res(2, 0);
        
        for(int i=0; i<n; i++){
            
            if(arr[abs(arr[i])-1] < 0){
                b = abs(arr[i]);
            }
                
            arr[abs(arr[i])-1] *= -1;
        }
        
        for(int i=0; i<n; i++){
            if((arr[i] > 0) && ((i+1) != b))
                a = i+1;
        }
        
        //int res[2];
        res[0] = b;
        res[1] = a;
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends