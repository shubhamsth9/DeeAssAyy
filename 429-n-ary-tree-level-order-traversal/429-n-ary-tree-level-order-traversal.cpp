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
public:
    vector<vector<int>> levelOrder(Node* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            vector<int> temp;
            int n = q.size();
            while(n--){
                Node* curr = q.front();
                q.pop();
                temp.emplace_back(curr->val);
                for(auto it:curr->children) q.push(it);
            }
            res.emplace_back(temp);
        }
        return res;
    }
};