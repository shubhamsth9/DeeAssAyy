/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* curr=root, *head = NULL, *tail = NULL;
        
        while(curr){
            if(curr->left){
                if(tail){
                    tail->next = curr->left;
                    tail = tail->next;
                }
                else{
                    head = tail = curr->left;
                }
            }
            if(curr->right){
                if(tail){
                    tail->next = curr->right;
                    tail = tail->next;
                }
                else{
                    head = tail = curr->right;
                }
            }
            curr = curr->next;
            if(!curr){
                curr = head;
                head = tail = NULL;
            }
        }
        
        return root;
    }
};