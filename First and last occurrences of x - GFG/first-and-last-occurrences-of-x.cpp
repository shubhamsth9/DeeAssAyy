// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> res;
    int l=0, h=n-1, first = -1, last = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid] >= x){
            if(arr[mid] == x) first = mid;
            h = mid - 1;
        }
        else l = mid + 1;
    }
    res.push_back(first);
    l = 0, h = n-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid] <= x){
            if(arr[mid] == x) last = mid;
            l = mid + 1;
        }
        else h = mid - 1;
    }
    res.push_back(last);
    return res;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends