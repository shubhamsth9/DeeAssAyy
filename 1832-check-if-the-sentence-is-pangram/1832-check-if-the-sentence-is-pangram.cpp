class Solution {
public:
    bool checkIfPangram(string s) {
        int res = 0;
        for(auto ch:s){
            res = (res | (1 << (ch-'a')));
        }
        return (res == ((1<<26) - 1));
    }
};