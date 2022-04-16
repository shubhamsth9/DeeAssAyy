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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                TreeNode* tempnode = q.front();
                q.pop();
                temp.push_back(tempnode->val);
                if(tempnode->left != NULL) q.push(tempnode->left);
                if(tempnode->right != NULL) q.push(tempnode->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};