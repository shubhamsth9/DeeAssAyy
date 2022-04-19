
class Solution {
public:
    TreeNode *first=NULL, *second=NULL, *prev=NULL;
    
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        
        if(prev && root->val < prev->val){
            if(!first)
                first = prev;
            second = root;
        }
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        swap(first->val, second->val);
    }
};