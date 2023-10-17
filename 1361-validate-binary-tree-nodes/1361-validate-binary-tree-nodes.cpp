class Solution {
    int findRoot(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);
        for (auto i = 0; i < n; ++i) {
            if (leftChild[i] != -1) parent[leftChild[i]] = i;
            if (rightChild[i] != -1) parent[rightChild[i]] = i;
        }
        int root = -1;
        for (auto i = 0; i < n; ++i) {
            if (parent[i] == -1 && root != -1) return -1; // more than 1 root
            if (parent[i] == -1) root = i;
        }
        return root;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1) return false;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        int cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (visited[cur]) return false;
            visited[cur] = true;
            if (leftChild[cur] != -1) {
                q.push(leftChild[cur]);
            }
            if (rightChild[cur] != -1) {
                q.push(rightChild[cur]);
            }
        }
        for (auto i : visited) {
            if (!i) return false;
        }
        return true;
    }
};
// 4
// [1,0,3,-1]
// [-1,-1,-1,-1]