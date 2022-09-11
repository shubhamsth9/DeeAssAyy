class Solution {
public:
    int partitionString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int res = 1, n=s.size(), flag = 0;
        // unordered_set<char> uset;
        for(int i=0; i<n; i++){
            if(flag & (1<<(s[i]-'a'))){
                res++;
                flag = 0;
            }
            flag = flag | (1<<(s[i]-'a'));
        }
        return res;
    }
};