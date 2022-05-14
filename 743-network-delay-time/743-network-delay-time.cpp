typedef pair<int, int> pii;

class Solution {
public:
//     void dfsutil(vector<vector<int>> adj, int n, int sv, int temp, int &res){
//         for(int i=sv; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(!visited[i][j] && adj[i][j] > 0){
//                     visited[i][j] = true;
//                     dfsutil(adj, n, )
//                 }
//             }
//         }
//     }
        
//     void dfs(vector<vector<int>> adj, int n, int sv, int temp, int &res){
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         int cnt = 0;
//         for(int i=sv; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(!visited[i][j] && adj[i][j] > 0){
//                     dfsutil(adj, n, i, temp, res);
//                     cnt++;
//                 }
//             }
//         }
        
//         if(cnt>1) res = -1;
//     }
        
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // vector<vector<int>> adj(n, vector<int>(n, 0));
        // for(int i=0; i<n; i++){
        //     adj[times[i][0]-1][times[i][1]-1] = times[i][2];
        // }
        // int res=-1;
        // dfs(adj, n, k-1, 0, res);
        vector<vector<pii> > g(n + 1);
        for (const auto& t : times) {
            g[t[0]].emplace_back(t[1], t[2]);
        }
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
		vector<bool> vis(n + 1, false);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.emplace(0, k);
        int u, v, w;
        while (!pq.empty()) {
            u = pq.top().second; pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};