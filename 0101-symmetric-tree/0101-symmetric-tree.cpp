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

// iterative solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root->left);
        s2.push(root->right);
        TreeNode* cur;
        while (!s1.empty() && !s2.empty()) {
            if (!s1.top() && !s2.top()) {
                s1.pop();
                s2.pop();
            }
            else if (!s1.top() || !s2.top()) return false;
            else if (s1.top()->val != s2.top()->val) return false;
            else {
                cur = s1.top();
                s1.pop();
                s1.push(cur->left);
                s1.push(cur->right);
                cur = s2.top();
                s2.pop();
                s2.push(cur->right);
                s2.push(cur->left);
            }
        }
        return s1.empty() && s2.empty();
    }
};

// recursive solution
// class Solution {
// private:
//     bool helper(TreeNode* a, TreeNode* b) {
//         if (!a && !b) return true;
//         if (!a || !b) return false;
//         if (a->val != b->val) return false;
//         return helper(a->left, b->right) && helper(a->right, b->left);
//     }
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;
//         return helper(root->left, root->right);
//     }
// };