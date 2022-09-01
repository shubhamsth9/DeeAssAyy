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
    int f(int maxv, TreeNode* root){
        if(root == NULL) return 0;
        if(root->val >= maxv){
            return 1 + f(root->val, root->left) + f(root->val, root->right);
        }
        else return f(maxv, root->left) + f(maxv, root->right);
        
    }
    int goodNodes(TreeNode* root) {
        return f(INT_MIN, root);
    }
};