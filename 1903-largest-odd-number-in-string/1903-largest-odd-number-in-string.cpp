class Solution {
public:
    string largestOddNumber(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        while(num.size()){
            if((num.back()-'0')&1) return num;
            num.pop_back();
        }
        return "";
    }
};