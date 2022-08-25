class Solution {
public:
    bool canConstruct(string note, string mag) {
        unordered_map<char, int> umap;
        for(char c:mag) umap[c]++;
        for(char c:note){
            if(umap.find(c) == umap.end() || umap[c] <= 0) return false;
            umap[c]--;
        }
        return true;
    }
};