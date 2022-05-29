// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int src, vector<int> adj[], vector<bool>& vis, int& cnt){
        vis[src] = true;
        cnt++;
        for(auto it:adj[src]){
            if(!vis[it])
                dfs(it, adj, vis, cnt);
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    for(int i=0; i<V; i++){
	        vector<bool> vis(V, false);
	        int cnt = 0;
	        dfs(i, adj, vis, cnt);
	        if(cnt == V) return i;
	    }
	    return -1;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends