class Solution {
public:
    bool isPossible(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int, int> cnt, tail;
        for(int it:nums) cnt[it]++;
        for(int it:nums){
            if(cnt[it] == 0) continue;
            cnt[it]--;
            if(tail[it-1]){
                tail[it-1]--;
                tail[it]++;
            }
            else if(cnt[it+1] && cnt[it+2]){
                cnt[it+1]--;
                cnt[it+2]--;
                tail[it+2]++;
            }
            else return false;
        }
        return true;
    }
};