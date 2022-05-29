// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<pair<int, pair<int, int>>> adj;
	    
	    for(int i=0;i<edges.size();i++){
	        int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj.push_back({u,{v,w}});
	    }
	    
	    vector<int> dist(n, 1e6+7);
	    dist[0]=0;
	    
	    for(int i=0;i<n-1;i++){
	        for(auto edge:adj){
	            int u=edge.first;
	            int v=edge.second.first;
	            int w=edge.second.second;
	            if(dist[v]>dist[u]+w){
	                
	                dist[v]=dist[u]+w;
	            }
	        }
	    }
	    
        for(auto edge:adj){
            int u=edge.first;
            int v=edge.second.first;
            int w=edge.second.second;
             // cout<<u<<" "<<v<<" "<<w<<endl;

            if(dist[v]>dist[u]+w){
                // cout<<"h";
                return 1;
            }
        }
        
	    return 0;
	   // vector<pair<int, pair<int, int>>> adj;
	    
	   // for(int i=0; i<edges.size(); i++){
	   //     int u = edges[i][0];
	   //     int v = edges[i][1];
	   //     int w = edges[i][2];
	   //     adj.push_back({u, {v, w}});
	   // }
	    
	   // vector<int> dist(n, INT_MAX);
	   // dist[0] = 0;
	    
	   // for(int i=0; i<n-1; i++){
	   //     for(auto it:adj){
	   //         int u = it.first;
	   //         int v = it.second.first;
	   //         int w = it.second.second;
	   //         if(dist[v] > dist[u] + w){
	   //             dist[v] = dist[u] + w;
	   //         }
	   //     }
	   // }
	    
    //     for(auto it:adj){
    //         int u = it.first;
    //         int v = it.second.first;
    //         int w = it.second.second;
    //         if(dist[v] > dist[u] + w){
    //             return 1;
    //         }
    //     }
	    
	   // return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends