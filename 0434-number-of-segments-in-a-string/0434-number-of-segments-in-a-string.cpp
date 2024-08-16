class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        
        int count = s[0] != ' ' ? 1 : 0;
        int n = s.size();
        for (int i = 1 ; i < s.size(); ++i) {
            if (s[i] != ' ' && s[i-1] == ' ') ++count;
        }

        return count;
    }
};
// ""