#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>

class Solution {
    // encode each word (removing inputs with duplicate chars), then dfs to find longest length
public:
    void dfs(vector<pair<int,int>>& encoded, int index, int cur, int curLength, int& ans) {
        ans = max(ans, curLength);
        if (index == encoded.size()) return;
        auto [encoding, length] = encoded[index];
        if ((cur & encoding) == 0) {
            dfs(encoded, index+1, cur | encoding, curLength + length, ans);
        }
        dfs(encoded, index+1, cur, curLength, ans);
    }

    int maxLength(vector<string>& arr) {
        vector<pair<int,int>> encoded; // <encoding, length>
        encoded.reserve(arr.size());
        unordered_set<char> s;  // check for duplicates inside arr[i];
        bool hasDuplicate;      // check for duplicates inside arr[i];
        int num;
        for (auto& i : arr) {
            num = 0;
            s.clear();
            hasDuplicate = false;
            for (char c : i) {
                num ^= (int) pow(2, c - 'a');
                if (!s.insert(c).second) {
                    hasDuplicate = true;
                    break;
                }
            }
            if (!hasDuplicate) encoded.emplace_back(num, i.size());
        }
        int ans = 0;
        dfs(encoded, 0, 0, 0, ans);
        return ans;
    }
};

// ["aa","bb"]
// ["ab","ba","cd","dc","ef","fe","gh","hg","ij","ji","kl","lk","mn","nm","op","po"]
// ["a", "abc", "d", "de", "def"]