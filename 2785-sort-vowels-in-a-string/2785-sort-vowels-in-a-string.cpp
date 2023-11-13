class Solution {
    bool helper(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
        }
        return false;
    }
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> v;
        v.reserve(n);
        for (auto i : s) {
            if (helper(i)) {
                v.emplace_back(i);
            }
        }
        sort(v.begin(), v.end());
        int index = 0;
        for (auto i = 0; i < n; ++i) {
            if (helper(s[i])) {
                s[i] = v[index];
                ++index;
            }
        }
        return s;
    }
};