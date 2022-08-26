class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(nullptr);
        
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        for(int i=0; i<32; i++){
            string tmp = to_string(1<<i);
            sort(tmp.begin(), tmp.end());
            
            if(s == tmp) return true;
        }
        return false;
    }
};