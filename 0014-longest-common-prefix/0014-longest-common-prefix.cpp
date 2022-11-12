class Solution {
public:
    string common(string &s1, string &s2){
        int n = min(s1.size(), s2.size());
        int i = 0;
        while(i<n && s1[i] == s2[i]) i++;
        return s1.substr(0, i);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string res = strs[0];
        int n = strs.size();
        for(int i=1; i<n; i++){
            res = common(res, strs[i]);
            if(res == "") return res;
        }
        return res;
    }
};