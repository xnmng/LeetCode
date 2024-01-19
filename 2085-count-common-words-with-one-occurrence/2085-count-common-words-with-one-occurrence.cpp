class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        for (auto i : words1) ++mp1[i];
        for (auto i : words2) ++mp2[i];
        int ans = 0;
        for (auto& [k,v] : mp1) {
            if (v == 1 && mp2[k] == 1) ++ans;
        }
        return ans;
    }
};

