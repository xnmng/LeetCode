class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        int index = 0;
        while (index < s.size()) {
            if (s[index] == 'X') {
                ++ans;
                s[index] = 'O';
                if (index+1 < s.size()) s[index+1] = 'O';
                if (index+2 < s.size()) s[index+2] = 'O';
                index += 3;
            } 
            else ++index;
        }
        return ans;
    }
};