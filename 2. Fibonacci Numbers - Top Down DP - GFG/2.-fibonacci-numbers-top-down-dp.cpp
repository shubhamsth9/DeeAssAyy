// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
#include <fstream>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

//Complete this function
class Solution
{
    public:
    //Function to find the nth fibonacci number using top-down approach.
    long long findNthFibonacci(int n, long long int dp[])
    {
        if(n == 1 || n == 2){
            dp[n-1] = 1;   
        }
        else if(dp[n] != 0) return dp[n-1];
        else dp[n-1] = findNthFibonacci(n-1, dp) + findNthFibonacci(n-2, dp);
        return dp[n-1];
    }

};

// { Driver Code Starts.

int main()
 {
    //initializing base value
    long long dp[100]={0};
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    
    //taking total testcases
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        //taking nth number 
        int number;
        cin>>number;
        
        //calling findNthFibonacci() function
        Solution obj;
        cout<<obj.findNthFibonacci(number, dp)<<endl;
    }
    
	return 0;
}
  // } Driver Code Ends