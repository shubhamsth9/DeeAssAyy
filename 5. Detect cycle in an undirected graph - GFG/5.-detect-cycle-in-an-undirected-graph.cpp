// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycleDfs(int s, int par, vector<int> adj[], vector<bool>& vis){
        vis[s] = true;
        
        for(auto it:adj[s]){
            if(!vis[it]){
                if(checkCycleDfs(it, s, adj, vis)){
                    return true;
                }
            }
            else if(it != par){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> vis(v, false);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(checkCycleDfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends