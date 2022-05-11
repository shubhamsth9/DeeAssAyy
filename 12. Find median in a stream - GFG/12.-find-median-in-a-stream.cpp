// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    
    void insertHeap(int &x)
    {
        int n1 = maxpq.size(), n2 = minpq.size();
        if(n1>n2){
            if(maxpq.top() > x){
                minpq.push(maxpq.top());
                maxpq.pop();
                maxpq.push(x);
            }
            else{
                minpq.push(x);
            }
        }
        else{
            if(n1 == 0) maxpq.push(x);
            else if(minpq.top() < x){
                maxpq.push(minpq.top());
                minpq.pop();
                minpq.push(x);
            }
            else{
                maxpq.push(x);
            }
            
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps() {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        int n1 = maxpq.size(), n2 = minpq.size();
        if(n1 > n2) return maxpq.top();
        return (maxpq.top() + minpq.top())/2.0 ;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends