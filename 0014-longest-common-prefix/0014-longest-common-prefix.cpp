class Solution {
public:
    // string common(string &s1, string &s2){
    //     int n = min(s1.size(), s2.size());
    //     int i = 0;
    //     while(i<n && s1[i] == s2[i]) i++;
    //     return s1.substr(0, i);
    // }
    
    string longestCommonPrefix(vector<string>& strs) {
        // if(strs.size() == 0) return "";
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs[n-1];
        string res = "";
        for(int i=0; i<a.size(); i++){
            if(a[i] == b[i]) res += a[i];
            else break;
        }
        return res;
    }
};