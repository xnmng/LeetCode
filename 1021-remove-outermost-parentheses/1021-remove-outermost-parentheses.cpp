class Solution {
public:
    string removeOuterParentheses(string s) {
        auto index{0};
        auto count{0};
        string ans;
        unordered_map<char, int> mp{
            {'(', 1},  
            {')', -1},  
        };
        while (index < s.size()) {
            // if currently count is 0, dont add
            // if after adding s[index] count becomes 0 dont add
            if (count != 0 && count + mp[s[index]] != 0) {
                ans += s[index];
            }
            count += mp[s[index]];
            ++index;
        }
        return ans;
    }
};