class Solution {
    // bool helper(string& s1, string& s2) {
    //     vector<int> v(26, 0);
    //     for (auto i : s1) {
    //         ++v[i - 'a'];
    //     }
    //     for (auto i : s2) {
    //         if (v[i - 'a'] > 0) return false;
    //     }
    //     return true;
    // }
public:
    int maxProduct(vector<string>& words) {
        vector<int> v;
        auto cur{0};
        for (auto i : words) {
            cur = 0;
            for (auto j : i) {
                cur |= static_cast<int>(pow(2, j - 'a'));
            }
            v.push_back(cur);
        }
        auto ans{0};
        for (auto i = 0; i < v.size(); ++i) {
            for (auto j = i+1; j < v.size(); ++j) {
                if ((v[i] & v[j]) == 0) {
                    ans = max(ans, 
                              static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};

// ["aab", "c"]
// ["eae","ea","aaf","bda","fcf","dc","ac","ce","cefde","dabae"]
