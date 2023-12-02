class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> v(26,0);
        for (auto i : chars) {
            ++v[i - 'a'];
        }
        int ans = 0;
        vector<int> temp;
        for (auto word : words) {
            temp = vector<int>(26, 0);
            ans += word.size();
            for (auto i : word) {
                ++temp[i - 'a'];
            }
            for (auto i = 0; i < 26; ++i) {
                if (v[i] < temp[i]) {
                    ans -= word.size();
                    break;
                }
            }
        }
        return ans;
    }
};