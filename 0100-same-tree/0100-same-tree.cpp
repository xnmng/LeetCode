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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ps;
        stack<TreeNode*> qs;
        ps.push(p);
        qs.push(q);
        TreeNode* pcur;
        TreeNode* qcur;
        while (!ps.empty() && !qs.empty()) {
            if (ps.empty() || qs.empty()) return false;
            pcur = ps.top();
            ps.pop();
            qcur = qs.top();
            qs.pop();
            if (pcur && qcur) {
                if (pcur->val != qcur->val) return false;
                ps.push(pcur->left);
                ps.push(pcur->right);
                qs.push(qcur->left);
                qs.push(qcur->right);
            }
            else if (!pcur && !qcur) continue;
            else return false;
        }
        return ps.empty() && qs.empty();
    }
};