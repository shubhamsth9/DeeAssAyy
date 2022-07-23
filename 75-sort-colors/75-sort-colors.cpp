class Solution {
public:
    void sortColors(vector<int>& arr) {
        
        int i=0, j=0, n=arr.size();
        while(j<n){
            if(arr[j] == 0){
                swap(arr[i], arr[j]);
                i++;
            }
            j++;
        }
        j = i;
        while(j<n){
           if(arr[j] == 1){
               swap(arr[i], arr[j]);
               i++;
           }
            j++;
        }
    }
};