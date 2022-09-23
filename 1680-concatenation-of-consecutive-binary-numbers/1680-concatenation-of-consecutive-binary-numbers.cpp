class Solution {
public:
    int concatenatedBinary(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        long res = 0, len = 0;
        int m = 1e9+7;
        for(int i=1; i<=n; i++){
            if((i & (i-1)) == 0) len++;
            res = (res << len)%m + i;
        }
        return res;
    }
};