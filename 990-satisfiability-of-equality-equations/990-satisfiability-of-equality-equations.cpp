class Solution {
public:
    int findRoot(int x, vector<int>& par){
        if(x != par[x]) par[x] = findRoot(par[x], par);
        return par[x];
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> par(26);
        for(int i=0; i<26; i++){
            par[i] = i;
        }
        
        for(string it:equations){
            int x = it[0]-'a', y = it[3]-'a';
            
            if(it[1] == '=')
                par[findRoot(x, par)] = findRoot(y, par);
        }
        
        for(string it:equations){
            int x = it[0]-'a', y = it[3]-'a';
            
            if(it[1] == '!' & findRoot(x, par) == findRoot(y, par))
                return false;
        }
        
        return true;
    }
};