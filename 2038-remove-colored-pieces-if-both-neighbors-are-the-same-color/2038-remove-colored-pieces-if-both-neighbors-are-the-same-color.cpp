class Solution {
public:
    bool winnerOfGame(string colors) {
        bool ans{false};
        int sum{0};
        int count{0};
        char cur{' '};
        for (auto i : colors) {
            if (i == 'A') {
                if (cur == 'A') ++count;
                else {
                    sum -= max(0, count - 2);
                    cur = 'A';
                    count = 1;
                }
            }
            else if (i == 'B') {
                if (cur == 'B') ++count;
                else {
                    sum += max(0, count - 2);
                    cur = 'B';
                    count = 1;
                }
            }
        }
        // cout << sum << "\n";
        cur == 'A' ? sum += max(0, count - 2) : sum -= max(0, count - 2);
        // cout << sum << "\n";
        return sum > 0;
    }
};

// "AAAABBBB"