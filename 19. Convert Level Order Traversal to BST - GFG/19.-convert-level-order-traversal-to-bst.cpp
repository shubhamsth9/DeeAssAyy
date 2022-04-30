// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++
void util(Node*& root, int val){
    Node *curr=root, *prev=NULL , *temp = new Node(val);
    while(curr){
        prev = curr;
        if(curr->data > val) curr = curr->left;
        else curr = curr->right;
    }
    if(prev->data > val) prev->left = temp;
    else prev->right = temp;
}


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    if(n == 0) return NULL;
    Node* root = new Node(arr[0]);
    for(int i=1; i<n; i++){
        util(root, arr[i]);
    }
    return root;
}
