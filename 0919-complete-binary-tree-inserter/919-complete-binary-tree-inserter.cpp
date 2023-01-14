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
class CBTInserter {
    vector<TreeNode*> v;
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto cur{q.front()};
            q.pop();
            v.push_back(cur);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    
    int insert(int val) {
        v.push_back(new TreeNode(val));
        if (v.size() % 2 == 0) {
            v[v.size()/2 - 1]->left = v.back();
        } else {
            v[v.size()/2 - 1]->right = v.back();
        }
        return v[v.size()/2 - 1]->val;
    }
    
    TreeNode* get_root() {
        return v[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */