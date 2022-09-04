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
    void pre(TreeNode* root, int dist, int lvl, map<int, vector<pair<int, int>>> &mp){
        if(root == NULL) return;
        mp[dist].push_back({lvl, root->val});
        pre(root->left, dist-1, lvl+1, mp);
        pre(root->right, dist+1, lvl+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        map<int, vector<pair<int, int>>> mp;
        pre(root, 0, 0, mp);
        vector<vector<int>> res;
        for(auto it:mp){
            auto temp = it.second;
            sort(temp.begin(), temp.end());
            vector<int> vec;
            int m = temp.size();
            for(int i=0; i<m; i++){
                if(i < m-1 && temp[i].first == temp[i+1].first){
                    vec.push_back(min(temp[i].second, temp[i+1].second));
                    vec.push_back(max(temp[i].second, temp[i+1].second));
                    i++;
                }
                else vec.push_back(temp[i].second);
            }
            res.push_back(vec);
        }
        return res;
    }
};