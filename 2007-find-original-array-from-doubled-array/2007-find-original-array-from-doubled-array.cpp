class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2) return {};
        vector<int> res;
        sort(begin(changed), end(changed));
        map<int, int> mp;
        for(auto it: changed) mp[it]++;
        for(int i=0; i<n; i++){
            if(mp[changed[i]] == 0) continue;
            if(mp[changed[i]*2] == 0) return {};
            res.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return res;
    }
};