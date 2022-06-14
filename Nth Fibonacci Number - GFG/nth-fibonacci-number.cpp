// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define mod 1000000007;

class Solution {
  public:
    long long int util(long long memo[], int n){
        if(memo[n] == 0){
            if(n == 0 || n == 1) return n;
            memo[n] = util(memo, n-1) + util(memo, n-2);
            return memo[n]%mod;
        }
        else return memo[n]%mod;
    }
    
    long long int nthFibonacci(long long int n){
        long long memo[n+1] = {0};
        
        return util(memo, n)%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends