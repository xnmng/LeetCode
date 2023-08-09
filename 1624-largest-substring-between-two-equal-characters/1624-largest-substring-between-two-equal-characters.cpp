class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v(26, -1);
        int ans{-1};
        for (int i = 0; i < s.size(); ++i) {
            if (v[s[i] - 'a'] != -1) {
                ans = max(ans, i - v[s[i] - 'a'] - 1);
            } else {
                v[s[i] - 'a'] = i;            
            }
        }
        return ans;
    }
};
// "mgntdygtxrvxjnwksqhxuxtrv"