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
    // parse graph, perform dfs on graph with start node as root
    // 2 pass
    // TODO: 1 pass solution
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> valToNode;
        unordered_map<int, vector<TreeNode*>> valToNeighbours;
        parse(root, valToNode, valToNeighbours);
        return dfs(valToNode[start], valToNeighbours, nullptr);
    }
    
    void parse(TreeNode* root, 
           unordered_map<int, TreeNode*>& valToNode, 
           unordered_map<int, vector<TreeNode*>>& valToNeighbours) {
        if (root) {
            valToNode[root->val] = root;
            if (root->left) {
                valToNeighbours[root->left->val].emplace_back(root);
                valToNeighbours[root->val].emplace_back(root->left);
                parse(root->left, valToNode, valToNeighbours);
            }
            if (root->right) {                
                valToNeighbours[root->right->val].emplace_back(root);
                valToNeighbours[root->val].emplace_back(root->right);
                parse(root->right, valToNode, valToNeighbours);
            }            
        }
    }
    
    int dfs(TreeNode* root, unordered_map<int, vector<TreeNode*>>& valToNeighbours, TreeNode* prev) {
        if (!root) return 0;
        int ans = 0;
        for (auto& i : valToNeighbours[root->val]) {
            if (i == prev) continue;
            ans = max(ans, 1 + dfs(i, valToNeighbours, root));
        }
        return ans;
    }
};
// [1,2,null,3,null,4,null,5]
// 4
// [1,2,null,3,null,4,null,5]
// 1