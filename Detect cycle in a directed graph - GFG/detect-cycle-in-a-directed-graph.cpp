// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int s, vector<int> adj[], vector<bool>& vis, vector<bool>& trail){
        vis[s] = true;
        trail[s] = true;
        
        for(auto it:adj[s]){
            if(!vis[it] && dfs(it, adj, vis, trail))
                return true;
            else if(trail[it] == true)
                return true;
        }
        trail[s] = false;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<bool> vis(v, false), trail(v, false);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, trail))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends