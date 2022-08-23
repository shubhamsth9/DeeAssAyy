class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int begin = 0, cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') {
                if(cnt++) res += "(";
            }
            else if(--cnt){
                res += ")";
            }
        }
        return res;
    }
};