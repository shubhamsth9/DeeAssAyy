// { Driver Code Starts
// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}// } Driver Code Ends



//Function to check if any pair exists in BST whose sum is equal to given value.

bool findPair(Node* root, int x) 
{
    if(root == NULL) return false;
    vector<int> res;
    stack<Node*> s1, s2;
    Node* curr=root;
    
    while(curr){
        s1.push(curr);
        curr = curr->left;
    }
    
    curr = root;
    while(curr){
        s2.push(curr);
        curr = curr->right;
    }
    
    while(s1.top() != s2.top()){
        
        int v1 = s1.top()->data, v2 = s2.top()->data;
        
        if(v1 + v2 == x) return true;
        if(v1 + v2 > x){
            curr = s2.top()->left;
            s2.pop();
            while(curr){
                s2.push(curr);
                curr = curr->right;
            }
        }
        else{
            curr = s1.top()->right;
            s1.pop();
            while(curr){
                s1.push(curr);
                curr = curr->left;
            }
        }
    }
    
    return false;
}



