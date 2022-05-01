class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> umap;
        int res = -1;
        for(int i=0; i<cards.size(); i++){
            if(umap.find(cards[i]) == umap.end()){
                umap[cards[i]] = i;
            }
            else{
                if(res == -1) res = i - umap[cards[i]]  + 1;
                else res = min(res, i - umap[cards[i]]  + 1);
                umap[cards[i]] = i;
            }
        }
        return res;
    }
};