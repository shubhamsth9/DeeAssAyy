class Solution {
public:
    int umap(char c){
        switch(c){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return -1;
        }
    }
    
    int romanToInt(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int res = umap(s.back()), n = s.size();
        
        for(int i=n-2; i>=0; i--){
            if(umap(s[i]) < umap(s[i+1])) res -= umap(s[i]);
            else res += umap(s[i]);
        }
        return res;
    }
};