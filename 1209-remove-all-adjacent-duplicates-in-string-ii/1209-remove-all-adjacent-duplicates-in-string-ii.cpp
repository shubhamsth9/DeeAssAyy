class Solution {
public:
    string removeDuplicates(string s, int k) {
        int cnt=0, i=0, j=1;
        while(j<s.length()){
            if(s[i] == s[j]){
                cnt++; j++;
                if(cnt == k){
                    s.erase(i, k);
                    i=max(0, i-k+1);
                    j=i+1, cnt=1;
                }
            }
            else{
                i=j; j=i+1;
                cnt=1;
            }
        }
        return s;
    }
};