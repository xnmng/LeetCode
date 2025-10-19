class Solution {
public:
    // https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/solutions/7285008/lexicographically-smallest-string-most-efficient-java-c-c-c-python3-go-js-ts
    //
    // each operation gives us a new state of a graph!
    // just bfs/dfs to find solution
    //
    // O(n^2) time, O(n) space
    // - each next state takes O(n) to generate, total O(n) states
    // - total possible strings is n, length of input str
    string findLexSmallestString(string str, int a, int b) {
        string ans = str;
        unordered_set<string> s;
        queue<string> q;
        q.push(str);
        s.insert(str);

        string cur;
        string next;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (ans > cur) ans = cur;

            next = cur;
            for (int i = 1; i < next.size(); i += 2) {
                next[i] = ((next[i] - '0' + a) % 10) + '0';
            }
            if (!s.contains(next)) {
                s.insert(next);
                q.push(next);
            }

            next = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!s.contains(next)) {
                s.insert(next);
                q.push(next);
            }
        }

        return ans;
    }
};