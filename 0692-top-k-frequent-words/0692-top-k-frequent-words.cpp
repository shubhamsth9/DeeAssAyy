class Solution {
public:
//     bool static comp(pair<int, string> &a, pair<int, string> &b){
//         if(a.first == b.first){
//             return a.second < b.second;
//         }
//         return a.first > b.first;
//     }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for(auto it:words){
            map[it]++;
        }
        vector<pair<int, string>> vec;
        for(auto it:map) vec.push_back({it.second, it.first});
        sort(vec.begin(), vec.end(), [](pair<int, string> &a, pair<int, string> &b) -> bool
             {
                 if(a.first == b.first){
                    return a.second < b.second;
                }
                return a.first > b.first;
             });
        vector<string> res;
        for(int i=0; i<k; i++) res.push_back(vec[i].second);
        return res;
    }
};