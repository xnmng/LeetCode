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
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            queue<Node*> next;
            vector<int> cur;
            while (!q.empty()) {
                auto node{q.front()};
                q.pop();
                cur.push_back(node->val);
                for (auto i : node->children) {
                    next.push(i);
                }
            }
            ans.push_back(cur);
            q = next;
        }
        
        return ans;
    }
};