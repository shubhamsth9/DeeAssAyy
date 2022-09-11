class Solution {
public:
    int partitionString(string s) {
        int res = 1, n=s.size();
        unordered_set<char> uset;
        for(int i=0; i<n; i++){
            if(uset.find(s[i]) != uset.end()){
                res++;
                uset.clear();
            }
            uset.insert(s[i]);
        }
        return res;
    }
};