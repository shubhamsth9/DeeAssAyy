// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    void merge(int arr[], int l, int mid, int r, int k){
        int temp[r-l+1];
        int p1 = l, p2 = mid+1, i=0;
        
        while(p1 <= mid && p2 <= r){
            if(abs(arr[p1]-k) < abs(arr[p2]-k)){
                temp[i++] = arr[p1++];
            }
            else if(abs(arr[p2]-k) < abs(arr[p1]-k)){
                temp[i++] = arr[p2++];
            }
            else{
                if(p1 < p2) temp[i++] = arr[p1++];
                else temp[i++] = arr[p2++];
            }
        }
        
        while(p1 <= mid) temp[i++] = arr[p1++];
        while(p2 <= r) temp[i++] = arr[p2++];
        
        i=0;
        for(int j=l; j<=r; j++){
            arr[j] = temp[i++];
        }
    }
    
    void mergeSort(int arr[], int l, int r, int k){
        if(l < r){
            int mid = l + (r - l)/2;
            mergeSort(arr, l, mid, k);
            mergeSort(arr, mid+1, r, k);
            merge(arr, l, mid, r, k);
        }
    }
    
    void sortABS(int arr[],int n, int k)
    {
       mergeSort(arr, 0, n-1, k);
    }

};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    Solution ob;
	   
	    ob.sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends