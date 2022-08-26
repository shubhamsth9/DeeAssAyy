class Solution {
public:
    bool reorderedPowerOf2(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        string s = sorted(n);
        for(int i=0; i<32; i++){
            if(s == sorted(1<<i)) return true;
        }
        return false;
    }
    string sorted(int n){
        string tmp = to_string(n);
        sort(tmp.begin(), tmp.end());
        return tmp;
    }
};