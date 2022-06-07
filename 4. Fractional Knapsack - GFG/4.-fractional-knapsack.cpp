// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool myComp(Item a, Item b){
    double r1 = (double)a.value/a.weight ;
    double r2 = (double)b.value/b.weight ;
    return (r1 > r2);
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // vector<pair<int, double>> unit_val;
        // for(int i=0; i<n; i++){
        //     unit_val.push_back({i, (arr[i].value/arr[i].weight)});
        // }
        sort(arr, arr+n, myComp);
        
        double res = 0.0;
        int i=0;
        
        while(i<n && w){
            if(arr[i].weight <= w){
                res += arr[i].value;
                w -= arr[i].weight;
                i++;
            }
            else{
                res += arr[i].value * ((double)w/arr[i].weight);
                return res;
            }
        }
        
        return res;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends