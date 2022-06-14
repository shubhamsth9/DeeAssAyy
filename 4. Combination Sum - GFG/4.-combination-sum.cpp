// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void util(int idx, int sum, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res){
        if(idx == arr.size()) return;
        if(sum == 0){
            res.push_back(temp);
            return;
        }
        
        for(int i = idx; i<arr.size(); i++){
            if(i > idx && arr[i] == arr[i-1]) continue;
            if(sum-arr[i] < 0) return;
            temp.push_back(arr[i]);
            util(i, sum-arr[i], arr, temp, res);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &arr, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(arr.begin(), arr.end());
        
        util(0, sum, arr, temp, res);
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends