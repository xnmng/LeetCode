class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> d;
        for (auto& i : s) {
            if (d.empty() || d.back() != i) {
                d.push_back(i);
            } else {
                d.pop_back();
            }
        }
        string ans;
        while (!d.empty()) {
            ans.push_back(d.front());
            d.pop_front();
        }
        return ans;
    }
};