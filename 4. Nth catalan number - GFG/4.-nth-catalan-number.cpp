// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    cpp_int util(int n, cpp_int res[]){
        if(n <= 1){
            res[n] = 1;
            return res[n];
        }
        if(res[n] != 0) return res[n];
        for(int i=0; i<n; i++){
            res[n] += util(i, res) * util(n-i-1, res);
        }
        return res[n];
    }
    
    cpp_int findCatalan(int n) 
    {
        cpp_int res[n+1] = {0};
        util(n, res);
        return res[n];
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends