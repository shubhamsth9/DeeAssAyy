// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfs(int src, vector<int> adj[], stack<int>&st, vector<bool>& vis){
	    vis[src] = true;
	    for(auto it:adj[src]){
	        if(!vis[it]){
	            dfs(it, adj, st, vis);
	        }
	    }
	    st.push(src);
	}
	
	void dfsrev(int src, vector<int> rev[], vector<bool>& vis){
	    vis[src] = true;
	    for(auto it:rev[src]){
	        if(!vis[it]){
	            dfsrev(it, rev, vis);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, st, vis);
            }
        }
        
        vector<int> rev[V];
        
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                rev[it].push_back(i);
            }
        }
        
        int cnt = 0;
        
        vector<bool> revVis(V, false);
        
        
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            if(!revVis[temp]){
                dfsrev(temp, rev, revVis);
                cnt++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends