class Solution {
public:
    string common(string l, string r){
        int len = min(l.size(), r.size());
        for(int i=0; i<len; i++){
            if(l[i] != r[i]) return l.substr(0, i);
        }
        return l.substr(0, len);
    }
    
    string lcp(int left, int right, vector<string>& strs){
        if(left == right) return strs[left];
        int mid = (left+right)/2;
        string l = lcp(left, mid, strs);
        string r = lcp(mid+1, right, strs);
        return common(l, r);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        return lcp(0, strs.size()-1, strs);
    }
};