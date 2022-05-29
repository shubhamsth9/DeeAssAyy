// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  void dfs(int src, int dest, vector<int> adj[], int& cnt){
      if(src == dest){
          cnt++;
          return;
      }
      for(auto it:adj[src])
          dfs(it, dest, adj, cnt);
  }
  
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        int cnt = 0;
        dfs(source, destination, adj, cnt);
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends