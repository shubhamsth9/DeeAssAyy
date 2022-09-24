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
    void pre(TreeNode* root, int sum, vector<int> temp, vector<vector<int>> &res){
        if(root == NULL) return;
        
        temp.push_back(root->val);
        sum -= root->val;
        
        if(sum == 0 && !root->left && !root->right){
            res.push_back(temp);
            return;
        }
        
        pre(root->left, sum, temp, res);
        pre(root->right, sum, temp, res);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        pre(root, targetSum, {}, res);
        return res;
    }
};