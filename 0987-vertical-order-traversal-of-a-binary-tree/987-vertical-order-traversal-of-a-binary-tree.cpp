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

// https://youtu.be/kqHNP6NTzME

class Solution {
    void dfs(TreeNode* cur, vector<pair<pair<int,int>,int>>& v, int x, int y) {
        if (!cur) return;
        v.push_back({{x,y}, cur->val});
        if (cur->left) dfs(cur->left, v, x+1, y-1);
        if (cur->right) dfs(cur->right, v, x+1, y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<pair<int,int>, int>> v;
        dfs(root, v, 0, 0);
        sort(v.begin(), v.end(), 
            [](pair<pair<int,int>, int> p1, pair<pair<int,int>, int> p2) {
                // same coordinate, compare by value
                if (p1.first == p2.first) {
                    return p1.second < p2.second;
                }
                // sort first by y value, then by x value
                if (p1.first.second == p2.first.second) {
                    return p1.first.first < p2.first.first;
                }
                return p1.first.second < p2.first.second;
            }
        );
        
        vector<vector<int>> ans;
        int coord{v[0].first.second};
        vector<int> cur{v[0].second};
        for (auto i = 1; i < v.size(); ++i) {
            // cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << "\n";
            if (coord == v[i].first.second) {
                cur.push_back(v[i].second);
            } else {
                // cout << v[i].second << "\n";
                ans.push_back(cur);
                coord = v[i].first.second;
                cur.clear();
                cur.push_back(v[i].second);
            }
        }
        ans.push_back(cur);
        return ans;
    }
};