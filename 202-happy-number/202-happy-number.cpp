class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(1){
            if(n == 1) return true;
            else{
                if(st.find(n) != st.end()) return false;
                else st.insert(n);
                int temp = 0;
                while(n){
                    temp += pow(n%10, 2);
                    n = n/10;
                }
                n = temp;
            }
        }
        return false;
    }
};