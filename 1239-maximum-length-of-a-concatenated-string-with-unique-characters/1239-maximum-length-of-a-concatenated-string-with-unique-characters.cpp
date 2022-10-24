#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>

class Solution {
private:
    void dfs(vector<int>& v, int& ans, int cur, int index) {
        if (index == v.size()) {
            ans = max(ans, __popcount(cur));
            return;
        }
        if ((cur & v[index]) == 0) {
            dfs(v, ans, cur | v[index], index+1);
        }
        dfs(v, ans, cur, index+1);
    }
public:
    int maxLength(vector<string>& arr) {
        auto ans{0};
        vector<int> v;
        unordered_set<int> s;
        v.reserve(arr.size());
        auto cur{0};
        auto isUnique{true};
        for (auto& i : arr) {
            cur = 0;
            isUnique = true;
            for (auto& c : i) {
                if (cur & static_cast<int>(pow(2, c - 'a' + 1))) {
                    isUnique = false;
                    break;
                }
                cur += static_cast<int>(pow(2, c - 'a' + 1));
            }
            if (isUnique && s.find(cur) == s.end()) {
                v.push_back(cur);
                s.insert(cur);
            }
        }
        for (auto i = 0; i < v.size(); ++i) {
            dfs(v, ans, v[i], i+1);
        }
        return ans;
    }
};

// ["aa","bb"]
// ["ab","ba","cd","dc","ef","fe","gh","hg","ij","ji","kl","lk","mn","nm","op","po"]
// ["a", "abc", "d", "de", "def"]