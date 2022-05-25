// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> res(V, INT_MAX);
        vector<bool> vis(V, false);
        res[S] = 0;
        
        for(int cnt=0; cnt<V; cnt++){
            int u = -1;
            for(int i=0; i<V; i++){
                if(!vis[i] && (u == -1 || (res[i] < res[u]))){
                    u = i;
                }
            }
            vis[u] = true;
            
            for(auto v: adj[u]){
                if( v[1]!=0 && !vis[v[0]]){
                        res[v[0]] = min(res[v[0]], res[u] + v[1]);
                }
            }
            
            // for(int i=0; i<adj[u].size(); i++){
                
            //     if((adj[u][i][1] != 0 && !vis[adj[u][i][0]])){
            //         res[adj[u][i][0]] = min(res[adj[u][i][0]], res[u] + res[adj[u][i][1]]);
            //     }
            // }
        }
        return res;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends