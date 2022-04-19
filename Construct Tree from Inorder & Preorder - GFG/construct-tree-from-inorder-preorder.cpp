// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* tree(int in[], int pre[], int strt, int end, int &preIndex){
        if(strt > end) return NULL;
        Node* root = new Node(pre[preIndex++]);
        int idx;
        for(idx=strt; idx <= end; idx++){
            if(in[idx] == root->data){
                break;
            }
        }
        root->left = tree(in, pre, strt, idx-1, preIndex);
        root->right = tree(in, pre, idx+1, end, preIndex);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex = 0;
        return tree(in, pre, 0, n-1, preIndex);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends