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
    vector<vector<int>> res;
public:
    void pre(TreeNode* root, int sum, int targetSum, vector<int>& temp){
        if(root == NULL) return;
        
        sum += root->val;
        temp.push_back(root->val);
        
        if(sum == targetSum && !root->left && !root->right){
            res.push_back(temp);
        }
        
        if(root->left) pre(root->left, sum, targetSum, temp);
        if(root->right) pre(root->right, sum, targetSum, temp);
        
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        pre(root, 0, targetSum, temp);
        return res;
    }
};