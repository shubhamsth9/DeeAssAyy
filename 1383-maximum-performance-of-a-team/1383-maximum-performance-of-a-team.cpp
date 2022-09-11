
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i)
            ess[i] = {efficiency[i], speed[i]};
        sort(rbegin(ess), rend(ess));
        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        for(auto& [e, s]: ess){
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9+7);
//         int res = 0, mod = 1e9+7, sum = 0;
//         vector<pair<int, int>> vp;
//         for(int i=0; i<n; i++){
//             vp.push_back({eff[i], spd[i]});
//         }
//         sort(vp.begin(), vp.end(), greater<int>);
//         for(int i=0; i<k; i++){
//             sum += vp[i][1];
//             pro = (sum * vp[i][0])%mod;
//             res = max(res, pro);
//         }
//         for(int i=k; i<n; i++){
            
//         }
//         return res%mod;
    }
};