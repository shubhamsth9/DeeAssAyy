// { Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int entry[], int exitt[], int n)
	{
	   sort(entry, entry+n);
	   sort(exitt, exitt+n);
	   vector<int> res(2);
	   res[0] = 1, res[1] = entry[0];
	   
	   int i=1, j=0, count=1;
	   
	   while(i<n && j<n){
	       if(entry[i] <= exitt[j]){
	           count++, i++;
	       }
	       else{
	           count--, j++;
	       }
	       if(count > res[0]){
	           res[0] = count;
	           res[1] = entry[i-1];
	       }
	   }
	   
	   return res;
	}

};

// { Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends