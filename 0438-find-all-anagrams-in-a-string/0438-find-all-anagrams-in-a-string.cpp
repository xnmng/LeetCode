// can consider the 2 vector, 1 count variable technique for better performance (problem 567)

class Solution {
private:
    bool check(vector<int>& v) {
        for (auto i : v) {
            if (i != 0) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> chars(26, 0);
        for (auto& i : p) ++chars[i - 'a'];
        vector<int> ans;
        for (auto i = 0; i < p.size(); ++i) {
            --chars[s[i] - 'a'];
            // for (auto i : chars) {
            //     cout << i << " ";
            // }
            // cout << "\n";
        }
        if (check(chars)) ans.push_back(0);
        for (auto i = p.size(); i < s.size(); ++i) {
            --chars[s[i] - 'a'];
            ++chars[s[i - p.size()] - 'a'];
            if (check(chars)) ans.push_back(i - p.size() + 1);
            // for (auto i : chars) {
            //     cout << i << " ";
            // }
            // cout << "\n";
        }
        return ans;
    }
};

// "aaaaaaaaaa"
// "aaaaaaaaaaaaa"