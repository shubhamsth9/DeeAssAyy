
class Solution {
public:
    TreeNode *first=NULL, *second=NULL, *prev;
    
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        
        if(first == NULL && root->val < prev->val){
            first = prev;
        }
        if(first != NULL && root->val < prev->val){
            second = root;
        }
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val, second->val);
    }
};