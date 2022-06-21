class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        if(n == 0 || n == 1) return 1;
        for(int i=2; i<n+1; i++){
            int curr = one + two;
            two = one;
            one = curr;
        }
        return one;
    }
};