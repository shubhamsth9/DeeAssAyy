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
    void fun(TreeNode* root, int &res, int path){
        if(!root) return;
        
        path = path^(1<<root->val);
        
        if(!root->left && !root->right){
            if((path & (path-1)) == 0) res++;
            return;
        }
        
        fun(root->left, res, path);
        fun(root->right, res, path);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int res = 0;
        fun(root, res, 0);
        return res;
    }
};