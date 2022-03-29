// { Driver Code Starts
// C++ program to find union of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    public:
    //Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(int arr1[], int arr2[], int n, int m) 
    { 
         int i=0, j=0, k=0;
         vector<int> res;
         while(i<n && j<m){
             if(arr1[i] == arr2[j]){
                 if(k==0 || res[k-1] != arr1[i]){
                     res.push_back(arr1[i]);
                     k++;
                 }
                 i++, j++;
             }
             else if(arr1[i] < arr2[j])
                i++;
            else
                j++;
         }
         return res;
    }

};

// { Driver Code Starts.
/* Driver program to test above function */
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        Solution ob;
        // Function calling 
        vector<int> v;
        v = ob.printIntersection(arr1, arr2, N, M); 
        
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";

        cout << endl;
    }
    
  return 0; 
} 
  // } Driver Code Ends