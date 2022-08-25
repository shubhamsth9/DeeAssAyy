class Solution {
public:
    int calculate(string s) {
        int n = s.size(), currNum = 0;
        char opr = '+';
        stack<int> st;
        
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                currNum = (currNum*10) + (s[i]-'0');
            }
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == n-1){
                if(opr == '-')
                    st.push(-currNum);
                else if(opr == '+')
                    st.push(currNum);
                else if(opr == '*'){
                    int stTop = st.top();
                    st.pop();
                    st.push(stTop*currNum);
                } else if (opr == '/') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop / currNum);
                }
                opr = s[i];
                currNum = 0;
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};