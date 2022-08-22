class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        
        int res = INT_MIN, n = pts.size();
        priority_queue<pair<int, int>> pq;
        
        pq.push({pts[0][1] - pts[0][0], pts[0][0]});
        
        for(int i=1; i<n; i++){
            int temp = pts[i][0] + pts[i][1];
            while(!pq.empty() && pts[i][0] - pq.top().second > k) pq.pop();
            if(!pq.empty()) res = max(res, temp+pq.top().first);
            pq.push({pts[i][1]-pts[i][0], pts[i][0]});
        }
        return res;
    }
};