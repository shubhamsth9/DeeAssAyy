class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char> uset;
        for(auto ch:s) uset.insert(ch);
        return (uset.size() == 26);
    }
};