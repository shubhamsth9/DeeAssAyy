// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    string s = "DURL";

class Solution{
    public:

    void util(int i, int j, string temp, vector<vector<int>> &m, int n, vector<string>& res){
        if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0) return;
        if(i == n-1 && j == n-1) res.push_back(temp);
        
        m[i][j] = 0;
        
        for(int k=0; k<4; k++){
            util(i + dx[k], j + dy[k], temp + s[k], m, n, res);
        }
        
        m[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        util(0, 0, "", m, n, res);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends