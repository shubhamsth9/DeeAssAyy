class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> vp= {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        string res;
        
        while(num > 0){
            for(auto it:vp){
                if(num >= it.first){
                    num -= it.first;
                    res += it.second;
                    break;
                }
            }
        }
        return res;
    }
};