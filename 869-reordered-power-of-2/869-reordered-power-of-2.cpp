class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(nullptr);
        
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        unordered_set<string> uset;
        
        for(int i=0; i<32; i++){
            string tmp = to_string(1<<i);
            sort(tmp.begin(), tmp.end());
            
            uset.insert(tmp);
        }
        if(uset.find(s) != uset.end()) return true;
        return false;
    }
};