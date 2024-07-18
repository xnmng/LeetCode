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

// TODO: read second solution
// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/solution/
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_set<TreeNode*> v; // leaf nodes; use set because we need to check for leaf node
        unordered_map<TreeNode*, vector<TreeNode*>> adjlist;
        helper(root, nullptr, v, adjlist);
        
        int ans = 0;
        
        for (auto leaf : v) {
            queue<TreeNode*> q;
            queue<TreeNode*> next;
            unordered_set<TreeNode*> visited;
            visited.reserve(adjlist.size());
            q.push(leaf);
            
            for (int i = 0; i <= distance; ++i) {
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    visited.insert(cur);
                    if (cur != leaf && v.find(cur) != v.end()) {
                        ++ans;
                    }
                    
                    for (auto adj : adjlist[cur]) {
                        if (visited.find(adj) == visited.end()) {
                            next.push(adj);
                        }
                    }
                }
                swap(q, next);
            }
            
        }
        
        return ans / 2;
    }
    
    // initializes leaf nodes and adjlist
    void helper(TreeNode* cur, TreeNode* prev, 
                unordered_set<TreeNode*>& v, unordered_map<TreeNode*, vector<TreeNode*>>& adjlist) {
        if (!cur) return;
        if (!cur->left && !cur->right) {
            v.insert(cur);
        }
        if (prev) {
            adjlist[cur].emplace_back(prev);
            adjlist[prev].emplace_back(cur);
        }
        helper(cur->left, cur, v, adjlist);
        helper(cur->right, cur, v, adjlist);
    }
};