class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
        vector<vector<int>> graph(n);
        //vector<bool> vis(n, false);
        unordered_set<int> uset(rest.begin(), rest.end());
        
        for(int i=0; i<n-1; i++){
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        
        //vis[0] = true;
        queue<int> q;
        q.push(0);
        int res = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int temp = q.front(); q.pop();
                //vis[temp] = true;
                res++;
                uset.insert(temp);
                for(auto it:graph[temp]){
                    if(uset.find(it) == uset.end()){
                        q.push(it);
                    }
                }
            }
        }
        
        return res;
    }
};