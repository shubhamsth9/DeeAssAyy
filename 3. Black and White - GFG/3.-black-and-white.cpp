// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends

bool isValid(int i, int j, int n, int m){
    if(i<n && i >= 0 && j < m && j >= 0) return true;
    return false;
}

//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    long long res = 0;
    long long mod = 1e9+7;
    vector<pair<int,int>>v={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<m; j++){
            int to_be_subtracted = 0;   
            for(auto x:v){
                int ii = i + x.first;
                int jj = j + x.second;
                if(isValid(ii, jj, n, m)){
                    to_be_subtracted++;
                }
            }
            res += ((n*m)-1-to_be_subtracted)%mod;
        }
    }
    return res%mod;
}