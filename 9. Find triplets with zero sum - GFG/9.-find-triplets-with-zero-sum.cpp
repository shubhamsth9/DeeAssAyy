// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr+n);
        if(arr[0] > 0 || arr[n-1] < 0) return false;
        for(int i=0; i<n-1; i++)
        {
            int sum = -1*arr[i];
            int l=i+1, h=n-1;
            while(l<h){
                if(arr[l] + arr[h] == sum)
                    return true;
                else if(arr[l] + arr[h] < sum)
                    l++;
                else
                    h--;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends