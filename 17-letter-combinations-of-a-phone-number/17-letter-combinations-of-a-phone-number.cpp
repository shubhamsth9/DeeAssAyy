class Solution {
public:
    const vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void util(int idx, string& digits, vector<string>& res, string tmp){
        if(idx == digits.length()) res.push_back(tmp);
        else{
            for(auto c : pad[digits[idx]-'0']){
                tmp.push_back(c);
                util(idx+1, digits, res, tmp);
                tmp.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string> res;
        util(0, digits, res, "");
        return res;
    }
};