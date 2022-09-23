class Solution {
public:
    int nofbits(int n){
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long long res = 0;
        int m = 1e9+7;
        for(int i=1; i<=n; i++){
            int len = nofbits(i);
            res = ((res << len) + i)%m;
        }
        return res;
    }
};