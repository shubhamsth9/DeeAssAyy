class Solution {
public:
//     bool fun(int n){
//         if(n/4 == 1 && n%4 == 0) return true;
//         if(n%4 != 0) return false;
//         return fun(n/4);
//     }
    
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n <= 0) return false;
        long long x = 4;
        while(x <= n){
            if((x^n) == 0) return true;
            x = (x << 2);
        }
        return false;
    }
};