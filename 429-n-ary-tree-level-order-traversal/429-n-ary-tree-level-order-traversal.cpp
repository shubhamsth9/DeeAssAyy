/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<vector<int>> res;
public:
    void dfs(Node* root, int lvl){
        if(!root) return;
        if(res.size() == lvl) res.push_back({});
        res[lvl].push_back(root->val);
        for(auto it:root->children) dfs(it, lvl+1);
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        dfs(root, 0);
        return res;
    }
};