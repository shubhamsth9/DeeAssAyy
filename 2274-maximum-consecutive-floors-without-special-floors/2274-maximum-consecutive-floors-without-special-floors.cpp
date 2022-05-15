class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(), special.end());
        if(special.size() == top-bottom+1) return 0;
        
        int res = 0;
        
        for(int i=1; i<special.size(); i++){
            res = max(res, special[i]-special[i-1]-1);
        }
        res = max(res, special[0]-bottom);
        res = max(res, top-special[special.size()-1]);
        
        return res;
    }
};