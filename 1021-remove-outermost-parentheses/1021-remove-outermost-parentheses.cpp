class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int begin = 0, cnt = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == 0){
                res += s.substr(begin+1, i-begin-1);
                begin = i+1;
            }
        }
        return res;
    }
};