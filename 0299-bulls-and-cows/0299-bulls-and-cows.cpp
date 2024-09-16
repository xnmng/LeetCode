class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        vector<int> a(10, 0);
        vector<int> b(10, 0);
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                ++a[secret[i] - '0'];
                ++b[guess[i] - '0'];
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; ++i) {
            cows += min(a[i], b[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};