/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool haveone(TreeNode* root){
    //     if(root == NULL) return false;
    //     bool left = haveone(root->left), right = haveone(root->right);
    //     if(!left) root->left = NULL;
    //     if(!right) root->right = NULL;
    //     // if(root->val == 1) return true;
    //     return root->val == 1 || left || right;
    // }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && root->left == NULL && root->right == NULL) root = NULL;
        return root ;
    }
};