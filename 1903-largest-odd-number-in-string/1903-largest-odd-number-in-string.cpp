class Solution {
public:
    string largestOddNumber(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        for(int i=num.size()-1; i >= 0; i--)
            if((num[i]-'0')%2 != 0)
                return num.substr(0, i+1);
        return "";
    }
};