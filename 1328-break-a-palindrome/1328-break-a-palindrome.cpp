class Solution {
public:
    string breakPalindrome(string p) {
        int n = p.size();
        if(n == 1) return "";
        int i = 0;
        while(i < n/2 && p[i] == 'a'){
            i++;
        }
        if(i == n/2){
            p[n-1] = 'b';
            return p;
        }
        p[i] = 'a';
        return p;
    }
};