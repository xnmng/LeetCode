class Solution {
private:
    bool check(char s1, char s2) {
        return abs(s1 - s2) == 32;
    }
    
public:
    string makeGood(string s) {
        stack<char> st;
        for (auto i : s) {
            if (!st.empty() && check(st.top(), i)) {
                st.pop();
            } else {
                st.push(i);
            }
        }
        string ans;
        ans.reserve(s.size());
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};