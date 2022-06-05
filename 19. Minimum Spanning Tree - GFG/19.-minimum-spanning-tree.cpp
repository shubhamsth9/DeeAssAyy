// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int> key(V, INT_MAX);
       vector<bool> mst(V, false);
       
       key[0] = 0;
       int sum = 0;
       
       for(int i = 0 ; i < V ; i++){
           int u = -1;
            for(int i=0; i<V; i++){
                if(!mst[i] && (u == -1 || key[u] > key[i])){
                    u = i;
                }
            }
            mst[u] = true;
           sum += key[u];
           for(auto it:adj[u]){
                int v = it[0], w = it[1];
                if(!mst[v] && w < key[v])
                    key[v] = w;
            }
       }
      
       return sum;
        // int res = 0;
        // vector<int> key(V, INT_MAX);
        // vector<bool> mst(V, false);
        // key[0] = 0;
        
        // for(int count=0; count<V; count++){
        //     int u = -1;
        //     for(int i=0; i<V; i++){
        //         if(!mst[i] && (u == -1 || key[u] > key[i])){
        //             u = i;
        //         }
        //     }
        //     mst[u] = true;
        //     res += key[u];
            
        // }
        // return res;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends