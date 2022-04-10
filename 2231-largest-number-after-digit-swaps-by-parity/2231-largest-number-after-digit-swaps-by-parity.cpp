class Solution {
public:
    int largestInteger(int num) {
        vector<int> a;
        while(num){
            a.push_back(num%10);
            num = num/10;
        }
        reverse(a.begin(), a.end());
        
        for(int i=0; i<a.size()-1; i++){
            int max_j = i;
            for(int j=i+1; j<a.size(); j++){
                if((a[j] > a[max_j]) && ((a[j]%2) == (a[i]%2))){
                    max_j = j;
                }
            }
            swap(a[i], a[max_j]);
        }
        
        int res = 0;
        
        for(int i=0; i<a.size(); i++){
            res = res*10 + a[i];
        }
        
        return res;
    }
};