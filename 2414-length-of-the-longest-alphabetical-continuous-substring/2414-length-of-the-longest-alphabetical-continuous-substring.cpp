class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.length(), res = 1, cnt = 1;
        
        for(int i=1; i<n; i++){
            if((s[i]-'a') == (s[i-1]-'a')+1){
                cnt++;
                res = max(res, cnt);
            }
            else cnt = 1;
        }
        return res;
    }
};