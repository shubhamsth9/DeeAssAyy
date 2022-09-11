class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int res = -1, cnt = 0;
        map<int, int> umap;
        for(int it:nums) if(it%2 == 0) umap[it]++;
        if(umap.size() == 0) return -1;
        else {
            for(auto it: umap){
                if(it.second > cnt){
                        res = it.first;
                        cnt = it.second;
                }
            }
        }
        return res;
    }
};