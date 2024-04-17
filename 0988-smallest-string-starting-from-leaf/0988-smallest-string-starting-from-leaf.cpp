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
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        string temp;
        dfs(root, ans, temp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(TreeNode* node, string& ans, string& temp) {
        temp += 'a' + node->val;
        // cout << node->val << " " << ans << " " << temp << "\n";
        if (!node->left && !node->right) {
            if (ans.empty()) ans = temp;
            else {
                // cout << "comparing " << ans << " " << temp << "\n";
                auto ansItr = ans.rbegin();
                auto tempItr = temp.rbegin();
                while (ansItr != ans.rend() && tempItr != temp.rend()) {
                    if (*ansItr != *tempItr) {
                        if (*tempItr < *ansItr) {
                            ans = temp;
                        }
                        break;
                    }
                    ++tempItr;
                    ++ansItr;
                }
                if (tempItr == temp.rend()) ans = temp;
                // cout << "ans is " << ans << "\n";
            }
        }
        else {
            if (node->left) dfs(node->left, ans, temp);
            if (node->right) dfs(node->right, ans, temp);
        }
        temp.pop_back();
    }
};