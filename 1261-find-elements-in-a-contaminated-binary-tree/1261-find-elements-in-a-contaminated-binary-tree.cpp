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
class FindElements {
    unordered_set<int> s;
public:
    FindElements(TreeNode* root) {
        clean(root, s, -1);
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
private:
    void clean(TreeNode* root, unordered_set<int>& s, int cur) {
        if (cur == -1) {
            cur = 0;
        }
        // cout << cur << "\n";
        s.insert(cur);
        if (root->left) clean(root->left, s, 2 * cur + 1);
        if (root->right) clean(root->right, s, 2 * cur + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */