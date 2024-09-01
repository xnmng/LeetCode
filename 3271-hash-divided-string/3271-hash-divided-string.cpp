class Solution {
public:
    // simulate the process
    string stringHash(string s, int k) {
        string ans;
        int count = 0;
        int sum = 0;
        for (char c : s) {
            sum += c - 'a';
            ++count;
            if (count == k) {
                ans += 'a' + (sum % 26);
                sum = 0;
                count = 0;
            }
        }
        return ans;
    }
};