class Solution {
public:
    string freqAlphabets(string s) {
        auto cur{0};
        string ans;
        while (cur < s.size()) {
            if (cur + 2 < s.size() && s[cur + 2] == '#') {
                // cout << s.substr(cur, 2) << "\n";
                // cout << static_cast<char>('a' + (stoi(s.substr(cur, 2)))) << "\n";
                ans += static_cast<char>('a' + (stoi(s.substr(cur, 2))) - 1);
                cur += 3; 
            } 
            else {
                // cout << static_cast<int>(s[cur] - '0' - 1) << "\n";
                ans += static_cast<char>('a' + static_cast<int>(s[cur] - '0') - 1);
                ++cur;
            }
            // cout << ans << "\n";
        }
        return ans;
    }
};