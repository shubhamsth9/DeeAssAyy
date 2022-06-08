// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        string res;
        int cnt = n;
        while(cnt && sum > 0){
            if(sum >= 9){
                res += '9';
                sum = sum - 9;
            }
            else{
                res += to_string(sum);
                sum = 0;
            }
            cnt--;
        }
        while(cnt) {
            res.push_back('0');
            cnt--;
        };
        if(res.length() == n && sum == 0) return res;
        return "-1";
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends