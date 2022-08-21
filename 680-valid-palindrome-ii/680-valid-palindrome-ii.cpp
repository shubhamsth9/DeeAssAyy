class Solution {
public:
    bool isPal(int i, int j, string s){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i] != s[j]){
                return isPal(i+1, j, s) || isPal(i, j-1, s);
            }
            i++, j--;
        }
        return true;
    }
};