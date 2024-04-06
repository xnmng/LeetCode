class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> se; // store indexes we want to exclude
        stack<int> st; // keep track of parentheses
        int n = s.size();
        for (auto i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    se.insert(i); // add extra ')' into set
                } else {
                    st.pop();
                }
            }
        }
        // add all extra '(' indexes into set
        while (!st.empty()) {
            se.insert(st.top());
            st.pop();
        }
        string ans;
        ans.reserve(n);
        for (auto i = 0; i < n; ++i) {
            if (se.find(i) == se.end()) ans += s[i]; // only add indexes not in set
        }
        return ans;
    }
};