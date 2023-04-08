/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// https://youtu.be/mQeF6bN8hMk
class Solution {
private:
    // create a node and recursively create its neighbours
    Node* dfs(unordered_map<Node*, Node*>& mp, Node* cur) {
        if (mp.find(cur) != mp.end()) return mp[cur];
        auto node{new Node(cur->val)};
        mp[cur] = node;
        for (auto i : cur->neighbors) {
            node->neighbors.push_back(dfs(mp, i));
        }
        return node;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        return dfs(mp, node);
    }
};