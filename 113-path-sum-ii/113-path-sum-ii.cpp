class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        if(!root) return ans;
         vector<int> p;
        dfs(root,0,p,targetSum);
        return ans;
    }
    
    void dfs(TreeNode* root, int sum, vector<int>&path,int targetSum)
    {
        if(!root->left && !root->right)
        {
            sum+=root->val;
            path.push_back(root->val);
            if(sum==targetSum)
                ans.push_back(path); 
            path.pop_back();
            return;
        }
        sum+=root->val;
        path.push_back(root->val);
        if(root->left) 
            dfs(root->left,sum,path,targetSum);
        if(root->right) 
            dfs(root->right,sum,path,targetSum);
        path.pop_back();
         
        
    }
};