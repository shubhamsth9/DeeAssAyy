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
       //vector<int> parent(V, -1);
       
       key[0] = 0;
       //parent[0] = -1;
       
       for(int i = 0 ; i < V ; i++){
           int mini = INT_MAX;
           int u;
           //Step 1 : Find node with min weight using key vector
           //We can also use priority queue to reduce the time complexity
           for(int v = 0 ; v < V ; v++){
               if(mst[v] == false && key[v] < mini){
                   //node with idx v has min weight
                   u = v;
                   mini = key[v];
               }
           }
           //Step 2 : Mark min weight node true
           mst[u] = true;
           
           //Step 3 : Traverse adjacent of u 
           for(auto neighbour : adj[u]){
               int v = neighbour[0]; //Neighbour node of u
               int w = neighbour[1]; //Weight from u to v
               //3.1 : If v is not in MST and its weight is < previous weight then update it
               if(mst[v] == false && w < key[v]){
                   key[v] = w;
                   //Initialize parent of v to u
                   //parent[v] = u;
               }
           }
       }
       int sum = 0;
       for(auto it : key){
           sum += it;
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
        //     for(auto it:adj[u]){
        //         if(!mst[it[0]] && it[1] + key[it[u]] < key[it[0]])
        //             key[it[0]] = it[1];
        //     }
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