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
                
                if(temp->left){
                    q.push(temp->left);
                    q.push(temp->right);
                    if(lvl%2 == 0){
                        temparr.push_back(temp->left);
                        temparr.push_back(temp->right);
                    }
                }
            }
            
            if(lvl%2 == 0 && temparr.size() != 0){
                for(int j=0; j<n; j++){
                    int k = temparr[j]->val;
                    temparr[j]->val = temparr[2*n - j - 1]->val;
                    temparr[2*n - j - 1]->val = k;
                }
            }
            
            lvl++;
        }
        return root;
    }
};