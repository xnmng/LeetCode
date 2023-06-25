class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(128,0);
        for (auto& i : t) ++v[i];
        auto count{t.size()};
        auto left{0};
        auto right{0};
        auto ans{INT_MAX};
        auto len{INT_MAX};
        
        while (right < s.size()) {
            if (v[(int) s[right]] > 0) {
                --count;
            }
            --v[(int) s[right]];
            while (count == 0) {
                if (right - left < len) {
                    len = right - left + 1;
                    ans = left;
                }
                ++v[(int) s[left]];
                if (v[(int) s[left]] > 0) ++count;
                ++left;
            }
            ++right;
        }
        
        return ans == INT_MAX ? "" : s.substr(ans, len);
    }
};