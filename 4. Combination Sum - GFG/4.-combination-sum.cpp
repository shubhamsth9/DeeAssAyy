// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void util(int idx, int sum, vector<int>& arr, vector<int> temp, vector<vector<int>>& res){
        if(sum == 0){
            res.push_back(temp);
            return;
        }
        if(sum < 0) return;
        
        for(int i = idx; i<arr.size(); i++){
            temp.push_back(arr[i]);
            if(sum-arr[i] < 0) return;
            util(i, sum-arr[i], arr, temp, res);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &arr, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> copy;
        set<int> st;
        
        for(int i=0; i<arr.size(); i++){
            st.insert(arr[i]);
        }
        for(auto it:st) copy.push_back(it);
        
        util(0, sum, copy, temp, res);
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