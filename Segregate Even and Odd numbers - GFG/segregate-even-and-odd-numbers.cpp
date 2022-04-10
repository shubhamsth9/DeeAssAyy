// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    sort(arr, arr+n);
	    int res[n];
	    int i=0, j=0, k=0;
	    
	    while(i<n){
	        if(arr[i]%2 == 0){
	            res[k] = arr[i];
	            k++;
	        }
	        i++;
	    }
	    while(j<n){
	        if(arr[j]%2 == 1){
	            res[k] = arr[j];
	            k++;
	        }
	        j++;
	    }
	    
	    for(int i=0; i<n; i++){
	        arr[i] = res[i];
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends