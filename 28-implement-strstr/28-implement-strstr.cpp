class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int n = needle.size(), m=haystack.size();
        if(n>m) return -1;
        for(int i=0; i<=m-n; i++){
            if(haystack[i] == needle[0] && haystack.substr(i, n) == needle) return i;
        }
        return -1;
    }
};