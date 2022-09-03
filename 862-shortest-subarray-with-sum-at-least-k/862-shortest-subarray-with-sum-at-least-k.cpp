typedef long long ll;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        ll res = 1e18, n = nums.size(), sum = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; 
        
        for(ll i=0; i<n; i++){
            sum += nums[i];
            if(sum >= k){
                res = min(res, i+1);
            }
            while(pq.size() && sum-pq.top().first >= k){
                res = min(res, i-pq.top().second);
                pq.pop();
            }
            
            pq.push({sum, i});
            if(res == 1) return 1;
        }
        
        return res == 1e18 ? -1 : res;
    }
};