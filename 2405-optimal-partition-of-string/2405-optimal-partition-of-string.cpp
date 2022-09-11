class Solution {
public:
    int partitionString(string s) {
        int res = 1;
        unordered_set<char> uset;
        for(auto ch:s){
            if(uset.find(ch) != uset.end()){
                res++;
                uset.clear();
            }
            uset.insert(ch);
        }
        return res;
    }
};