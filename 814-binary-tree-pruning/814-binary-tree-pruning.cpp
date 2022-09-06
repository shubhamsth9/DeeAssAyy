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
    bool haveone(TreeNode* root){
        if(root == nullptr) return false;
        bool left = haveone(root->left), right = haveone(root->right);
        if(!left) root->left = nullptr;
        if(!right) root->right = nullptr;
        if(root->val == 1) return true;
        return left | right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root->val == 0 && !haveone(root)) return nullptr;
        haveone(root);
        return root;
    }
};