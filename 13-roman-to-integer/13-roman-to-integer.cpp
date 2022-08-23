class Solution {
public:
    int romanToInt(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char, int> umap = {
            { 'I' , 1 },
           { 'V' , 5 },
           { 'X' , 10 },
           { 'L' , 50 },
           { 'C' , 100 },
           { 'D' , 500 },
           { 'M' , 1000 }
        };
        
        int res = umap[s.back()], n = s.size();
        
        for(int i=n-2; i>=0; i--){
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) res -= 1;
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) res -= 10;
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) res -= 100;
            else res += umap[s[i]];
        }
        return res;
    }
};