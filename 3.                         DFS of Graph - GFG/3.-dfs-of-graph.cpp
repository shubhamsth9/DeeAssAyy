// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void util(int v, int sv, vector<int> adj[], vector<bool>& visited, vector<int>& res){
        if(res.size() == v) return;
        
        res.push_back(sv);
        visited[sv] = true;
        
        for(auto i:adj[sv]){
            if(!visited[i]){
                
                util(v, i, adj, visited, res);
            }
        }
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> res;
        vector<bool> visited(v, false);
        util(v, 0, adj, visited, res);
        return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends