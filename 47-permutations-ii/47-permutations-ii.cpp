class Solution {
public:
    void util(vector<int>& nums, int n, unordered_map<int, int>& umap, vector<int> temp, vector<vector<int>>& res){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        for(auto i = umap.begin(); i != umap.end(); i++){
            int num = i->first, cnt = i->second;
            if(cnt == 0) continue;
            temp.push_back(num);
            umap[num]--;
            util(nums, n, umap, temp, res);
            temp.pop_back();
            umap[num]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++){
            umap[nums[i]]++;
        }
        util(nums, nums.size(), umap, temp, res);
        return res;
    }
};