// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> temp(nums.begin(), nums.end());
	    sort(temp.begin(), temp.end());
	    unordered_map<int, int> umap;
	    for(int i=0; i<nums.size(); i++){
	        umap[temp[i]] = i;
	    }
	    int i=0;
	    int res = 0;
	    while(i<nums.size()){
	        if(nums[i] == temp[i]) i++;
	        else{
	            swap(nums[i], nums[umap[nums[i]]]);
	            res++;
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends