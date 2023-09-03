class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for (auto i = 0; i < arr.size(); ++i) {
            ++mp[target[i]];
            --mp[arr[i]];
        }
        for (auto i : mp) {
            if (i.second != 0) return false;
        }
        return true;
    }
};