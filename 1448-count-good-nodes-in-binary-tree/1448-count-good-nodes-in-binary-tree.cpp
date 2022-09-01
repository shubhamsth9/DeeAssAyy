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
    int f(TreeNode* root, int maxv){
        if(root == NULL) return 0;
        if(root->val >= maxv){
            return 1 + f(root->left, root->val) + f(root->right, root->val);
        }
        else return f(root->left, maxv) + f(root->right, maxv);
        
    }
    int goodNodes(TreeNode* root) {
        
        return f(root, INT_MIN);
    }
};