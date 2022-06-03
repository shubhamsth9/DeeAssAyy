// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
//   void dfs(int src, int parent, int& t, vector<int>adj[], vector<int>& disc, vector<int>& low, vector<bool>& vis, vector<bool>& ap){
//       vis[src] = true;
//       disc[src] = low[src] = t;
//       t++;
//       int cnt = 0;
      
//       for(auto it:adj[src]){
//           if(!vis[it]){
//               cnt++;
//               dfs(it, src, t, adj, disc, low, vis, ap);
//               low[src] = min(low[src], low[it]);
//               if(low[it] >= disc[src] && parent != -1) ap[src] = true;
//           }
//           else if(it != parent) low[src] = min(low[src], low[it]);
//       }
//       if(parent == -1 && cnt >= 2) ap[src] = true;
//   }
  
    void dfs(int node, int parent, int &timer, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<bool> &vis, vector<bool> &isArticulation){
                 vis[node] = 1;
                 tin[node] = low[node] = timer++;
                 int child = 0;
                 for(auto it: adj[node]){
                     if(!vis[it]){
                         dfs(it, node, timer, adj, tin, low, vis, isArticulation);
                         low[node] = min(low[it], low[node]);
                         if(low[it] >= tin[node] && parent != -1)
                            isArticulation[node] = 1;
                        child++;
                     }
                     else
                        low[node] = min(low[node], tin[it]);
                 }
                 
                 if(parent == -1 && child > 1)
                    isArticulation[node] = 1;
             }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        int parent = -1;
        vector<int> disc(V), low(V);
        vector<bool> vis(V, false), ap(V, false);
        int t = 0;
        
        dfs(0, parent, t, adj, disc, low, vis, ap);
        
        vector<int> res;
        for(int i=0; i<V; i++){
            if(ap[i]) res.push_back(i);
        }
        if(res.size() == 0) return {-1};
        return res;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends