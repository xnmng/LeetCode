class Solution {
private:
    bool check(char s1, char s2) {
        return abs(s1 - s2) == 32;
    }
    
public:
    string makeGood(string s) {
        deque<char> st;
        for (auto i : s) {
            if (!st.empty() && check(st.back(), i)) {
                st.pop_back();
            } else {
                st.push_back(i);
            }
        }
        string ans;
        ans.reserve(st.size());
        while (!st.empty()) {
            ans.push_back(st.front());
            st.pop_front();
        }
        return ans;
    }
};