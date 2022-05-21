// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycleBfs(int s, vector<int> adj[], vector<bool>& vis){
        queue<pair<int, int>> q;
        q.push({s, -1});
        vis[s] = true;
        
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push({it, node});
                    vis[it] = true;
                }
                else if(it != par){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> vis(v, false);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(checkCycleBfs(i, adj, vis))
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