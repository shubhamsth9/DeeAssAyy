class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(auto ch:s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else{
                if(st.size() && (ch - st.top() == 1 || ch - st.top() == 2)){
                    st.pop();
                }
                else return false;
            }
        }
        return st.size()==0;
    }
};