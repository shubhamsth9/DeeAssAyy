class Solution {
public:
    int rev(int n)
    {
        int x = 0;
        while (n > 0) {
            x = x * 10 + n % 10;
            n = n / 10;
        }
        return x;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i<=num; i++){
            if(i + rev(i) == num) return true;
        }
        return false;
    }
};