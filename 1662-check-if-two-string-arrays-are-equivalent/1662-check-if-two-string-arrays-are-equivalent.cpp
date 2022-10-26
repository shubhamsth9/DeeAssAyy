class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1, w2;
        for(auto str:word1) w1 += str;
        for(auto str:word2) w2 += str;
        return (w1 == w2);
    }
};