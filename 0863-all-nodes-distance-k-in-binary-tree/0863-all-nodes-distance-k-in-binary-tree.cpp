/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<int,vector<int>>& mp) {
        if (parent) {
            mp[root->val].emplace_back(parent->val);
        }
        if (root->left) {
            mp[root->val].emplace_back(root->left->val);
            dfs(root->left, root, mp);
        }
        if (root->right) {
            mp[root->val].emplace_back(root->right->val);
            dfs(root->right, root, mp);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adjlist;
        dfs(root, nullptr, adjlist);
        unordered_set<int> s;
        queue<int> q;
        queue<int> next;
        q.push(target->val);
        auto count{0};
        int cur;
        vector<int> ans;
        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (count == k) {
                    ans.emplace_back(cur);
                } else {
                    s.insert(cur);
                    for (auto& i : adjlist[cur]) {
                        if (s.find(i) != s.end()) continue;
                        next.push(i);
                    }
                }
            }
            swap(q, next);
            ++count;
        }
        // for (auto [k,v] : adjlist) {
        //     cout << k << "\n";
        //     for (auto i : v) {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }
        return ans;
    }
};