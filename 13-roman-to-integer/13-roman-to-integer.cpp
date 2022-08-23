class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        int res = 0, n = s.size();
        
        res += umap[s.back()];
        
        for(int i=n-2; i>=0; i--){
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) res -= 1;
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) res -= 10;
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) res -= 100;
            else res += umap[s[i]];
        }
        return res;
    }
};