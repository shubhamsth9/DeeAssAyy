class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int i=0;
        while(res != strs[0]){
            char c = strs[0][i];
            for(auto str:strs){
                if(str.size() < i+1) return res;
                if(str[i] != c) return res;
            }
            res += c;
            i++;
        }
        return res;
    }
};