class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> umap;
        int n = arr.size();
        //sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            umap[arr[i]]++;
        }
        
        multiset<int, greater<int>> mset;
        
        for(auto it:umap) mset.insert(it.second);
        
        int cnt = 0;
        int k = n;
        for(auto it:mset){
            cnt++;
            k -= it;
            if(k <= n/2) break;
        }
        
        return cnt;
    }
};