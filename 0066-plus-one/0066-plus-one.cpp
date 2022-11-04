class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = digits.size();
        for(int i = n-1; i>=0; i--){
            if(digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};