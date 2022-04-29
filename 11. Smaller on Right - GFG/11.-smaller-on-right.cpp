#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n){
    int res = 0;
    set<int> st;
    for(int i=n-1; i>=0; i--){
        st.insert(arr[i]);
        int temp = distance(st.begin(), st.find(arr[i]));
        res = max(res, temp);
    }
    return res;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cout<<solve(arr, n)<<endl;
	}
	return 0;
}