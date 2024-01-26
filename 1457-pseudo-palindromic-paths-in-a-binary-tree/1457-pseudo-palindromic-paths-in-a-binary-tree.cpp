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
    // dfs tree, keeping track of counts. 
    // if at leaf node odd count <= 1, increment ans variable
    //
    // as a (small) optimization (SC still going to be linear), 
    // dont keep track of counts, simply keep track of true/false
    //      e.g. start with all digits false, flip the digits at each node
    //          at leaf, make sure that at most 1 flag is true
    // since we only need to keep track of 9 digits (0 to 9),
    // we can also use an integer (32 bits) to keep track of these 10 digits
    // this will be truly O(1) space
    // https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/solutions/648534/java-c-python-at-most-one-odd-occurrence/?envType=daily-question&envId=2024-01-24

int pseudoPalindromicPaths (TreeNode* root, int count = 0) {
        if (!root) return 0;
        count ^= 1 << (root->val - 1);
        return pseudoPalindromicPaths(root->left, count) 
                + pseudoPalindromicPaths(root->right, count) 
                + (!root->left && !root->right && (count & (count-1)) == 0);
    }
};

//     int pseudoPalindromicPaths (TreeNode* root) {
//         int ans = 0;
//         int count = 0;
//         dfs(root, count, ans);
//         return ans;
//     }
// private:
//     void dfs(TreeNode* root, int count, int& ans) {
//         if (!root) return;
//         count ^= 1 << (root->val - 1);
//         if (!root->left && !root->right && (count & (count-1)) == 0) ++ans;
//         dfs(root->left, count, ans);
//         dfs(root->right, count, ans);
//     }
// };