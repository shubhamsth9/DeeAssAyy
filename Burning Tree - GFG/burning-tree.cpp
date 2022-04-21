// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<Node*> pathToTarget;
    
    int height(Node* root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh, rh)+1;
    }
    
    void constructPath(Node* root, vector<Node*> tempPath, int target){
        if(root == NULL) return;
        if(root->data == target){
            tempPath.push_back(root);
            int n=tempPath.size();
            int i=0;
            while(n--){
                pathToTarget.push_back(tempPath[i++]);
            }
            return;
        }
        tempPath.push_back(root);
        constructPath(root->left, tempPath, target);
        constructPath(root->right, tempPath, target);
    }
  
    int minTime(Node* root, int target) 
    {
        if(target == root->data) return height(root)-1;
        vector<Node*> tempPath;
        constructPath(root, tempPath, target);
        int res=0;
        int n = pathToTarget.size();
        int k = height(pathToTarget[n-1])-1;
        
        for(int i=0; i<n-1; i++){
            int h=0;
            if(pathToTarget[i]->left == pathToTarget[i+1]){
                h = height(pathToTarget[i]->right);
            }
            else
                h = height(pathToTarget[i]->left);
                
            res = max(res, n-i+h-1);
        }
        
        return max(res, k);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends