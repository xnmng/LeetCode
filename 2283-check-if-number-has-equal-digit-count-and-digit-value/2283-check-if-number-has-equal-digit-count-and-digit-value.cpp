class Solution {
public:
    bool digitCount(string num) {
        vector<int> v(10, 0);
        for (auto i : num) {
            ++v[i - '0'];
        }
        for (auto i = 0; i < num.size(); ++i) {
            if (v[i] != (num[i] - '0')) return false;
        }
        
        return true;
    }
};