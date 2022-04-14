// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    int partition(int arr[], int l, int h, int k){
        int pivot = arr[h];
        int lo=l, hi=h-1, i=l;
        while(lo<=hi){
            if(arr[i] < pivot){
                swap(arr[i], arr[lo]);
                lo++, i++;
            }
            else{
                swap(arr[i], arr[hi]);
                hi--;
            }
        }
        swap(arr[i], arr[h]);
        return i;
    }
    
    int kthSmallest(int arr[], int n, int k)
    {
         int l=0, r=n-1;
         while(l <= r){
             int p = partition(arr, l, r, k);
             if(p == k-1) return arr[p];
             else if(p > k-1) r = p-1;
             else l = p+1;
         }
         return -1;
    }
};


// { Driver Code Starts.
int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    Solution ob;
	    cout << ob.kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}  // } Driver Code Ends