// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        int indegree[v] = {0};
        
        for(int i=0; i<v; i++){
            for(int j:adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int cnt = 0;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cnt++;
            
            for(auto it:adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        return (!(cnt == v));
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