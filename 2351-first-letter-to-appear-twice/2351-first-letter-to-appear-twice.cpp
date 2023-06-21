class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26, 0);
        for (auto i : s) {
            if (v[i - 'a'] == 1) return i;
            ++v[i - 'a'];
        }
        return '.'; // shouldnt happen based on TC requirements
    }
};