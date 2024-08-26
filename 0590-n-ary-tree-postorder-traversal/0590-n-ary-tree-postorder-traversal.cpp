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

// TODO: iterative (and without reverse)
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        for (auto i : root->children) {
            auto res = postorder(i);
            ans.insert(ans.end(), res.begin(), res.end());
        }
        ans.emplace_back(root->val);
        return ans;
    }
};