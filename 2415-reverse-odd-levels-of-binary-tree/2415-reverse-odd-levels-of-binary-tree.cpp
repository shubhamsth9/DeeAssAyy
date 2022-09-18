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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> temparr;
            
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front(); q.pop();
                temparr.push_back(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            if(lvl&1){
                n = temparr.size();
                for(int j=0; j<n/2; j++){
                    swap(temparr[j]->val, temparr[n - j - 1]->val);
                }
            }
            
            lvl ^= 1;
        }
        return root;
    }
};