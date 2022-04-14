// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 

class Solution{
    public:
    
    long long countPairs(int x[], int y[], int m, int n)
    {
       long long res=0;
       sort(y, y+n);
       int count1=0, count2=0, count3=0, count4=0;
       
       for(int i=0; i<n; i++){
           if(y[i] == 1) count1++;
           if(y[i] == 2) count2++;
           else if(y[i] == 3) count3++;
           else if(y[i] == 4) count4++;
           else if(y[i] > 4) break;
       }
       
       for(int i=0; i<m; i++){
           
           if(x[i] != 1){
               int* indx = upper_bound(y, y+n, x[i]);
               res += (y+n)-indx;
           }
           
           if(x[i] > 1) res += count1;
           if(x[i] == 2) res = res - count3 - count4;
           else if(x[i] == 3) res += count2;
       }
       
       return res;
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends