// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    void dfs(int src, int& timer, vector<int> adj[], vector<vector<int>>& res, vector<int>& disc, vector<int>& low, vector<bool>& inStack, stack<int>& st){
         disc[src] = low[src] = timer;
         timer++;
         st.push(src);
         inStack[src] = true;
         
         for(auto it:adj[src]){
             if(disc[it] == -1){
                 dfs(it, timer, adj, res, disc, low, inStack, st);
                 low[src] = min(low[src], low[it]);
             }
             else if(inStack[it]){
                 low[src] = min(low[src], disc[it]);
             }
         }
         
         if(low[src] == disc[src]){
             vector<int> temp;
             while(st.top() != src){
                 temp.push_back(st.top());
                 inStack[st.top()] = false;
                 st.pop();
             }
             temp.push_back(st.top());
             inStack[st.top()] = false;
             st.pop();
             sort(temp.begin(), temp.end());
             res.push_back(temp);
         }
         
    }
 
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>> res;
        int timer = 0;
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(disc[i] == -1)
                dfs(i, timer, adj, res, disc, low, inStack, st);
        }
        sort(res.begin(), res.end());
        return res;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends