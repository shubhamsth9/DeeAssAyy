// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    long long int countAndMerge(long long arr[], int l, int mid, int h){
        int n1 = mid-l+1, n2 = h-mid;
        long long left[n1], right[n2];
        for(int i=0; i<n1; i++) left[i] = arr[l+i];
        for(int i=0; i<n2; i++) right[i] = arr[mid+i+1];
        long long res=0, i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++;
            }
            else{
                arr[k] = right[j];
                j++;
                res += n1-i;
            }
            k++;
        }
        while(i<n1){
            arr[k] = left[i];
            i++, k++;
        }
        while(j<n2){
            arr[k] = right[j];
            j++, k++;
        }
        return res;
        
    }
  
    long long int countInversion(long long arr[], int l, int h){
        long long res = 0;
        if(l < h){
            long long mid = (l+h)/2;
            res += countInversion(arr, l, mid);
            res += countInversion(arr, mid+1, h);
            res += countAndMerge(arr, l, mid, h);
        }
        return res;
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        return countInversion(arr, 0, n-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends