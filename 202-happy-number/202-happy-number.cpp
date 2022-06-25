class Solution {
public:
    int squareSum(int n){
        int temp = 0;
            while(n){
                temp += pow(n%10, 2);
                n = n/10;
            }
        return temp;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
            if(fast == 1) return true;
        }while(slow != fast);
        return slow == 1;
    }
};