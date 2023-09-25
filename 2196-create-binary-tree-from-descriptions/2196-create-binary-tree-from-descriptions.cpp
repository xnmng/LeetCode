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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> s;
        int parent;
        int child;
        bool isLeft;
        for (auto i : descriptions) {
            parent = i[0];
            child = i[1];
            isLeft = i[2];
            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
                s.insert(parent);
            }
            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            } else {
                s.erase(child);
            }
            if (isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }
        }
        return mp[*s.begin()];
    }
};