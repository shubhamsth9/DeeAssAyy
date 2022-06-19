// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    long long util(int n, vector<long long>& res){
        if(n == 1 || n == 0) return res[n];
        if(res[n] != 0) return res[n];
        res[n] = util(n-1, res) + util(n-2, res);
        return res[n];
    }
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long> res(n, 0);
        res[0] = 1;
        if(n>1) res[1] = 1;
        util(n-1, res);
        return res;
    }
};

// { Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends