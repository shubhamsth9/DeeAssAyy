// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    // arr[]: input array
    // n: size of array
    // x: element to find index
    //Function to find index of element x in the array if it is present.
    int closer(int arr[],int n, int x)
    {
        int l=0, h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid] == x) return mid;
            if(arr[mid] > x){
                if(mid+1 < n && arr[mid+1] > x)
                    h = mid-1;
                else
                    l = mid + 1;
            }
            else{
                if(mid-1 >= 0 && arr[mid-1] < x)
                    l = mid+1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};


// { Driver Code Starts.

int main() {
    
    cin.tie(NULL);
    
	int t;
	cin >> t;
	
	while(t--){
	  
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    int x;
	    cin >> x;
	    Solution obj;
	    int res = obj.closer(arr,n,x);
	    
	    cout << res << endl;
	}
	
	return 0;
}  // } Driver Code Ends