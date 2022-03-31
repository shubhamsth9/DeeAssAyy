class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, res=0;
        unordered_set<char> set;
        while(j<s.size()){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j]);
                res = max(res, j-i+1);
            }
            else{
                while(set.find(s[j]) != set.end()){
                    set.erase(s[i]);
                    i++;
                }
                set.insert(s[j]);
            }
            j++;
        }
        return res;
    }
};