class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2) return {};
        vector<int> res;
        map<int, int> mp;
        for(auto it: changed) mp[it]++;
        for(auto it:mp){
            if(it.second == 0) continue;
            if(mp.find(it.first*2) == mp.end() || mp[it.first] > mp[it.first*2]) return {};
            else {
                if(it.first == 0){
                    if(it.second%2) return {};
                    for(int i=0; i<(it.second/2); i++) res.push_back(0);
                    
                }
                else{
                    for(int i=0; i<it.second; i++){
                        res.push_back(it.first);
                        mp[it.first]--;
                        mp[it.first*2]--;
                    }
                }
                
            }
        }
        return res;
    }
};