class Solution {
public:
    bool canAliceWin(int n) {
        bool isAlice = true;
        int count = 10;
        while (n > 0) {
            if (n < count) break;
            n -= count;
            --count;
            isAlice = !isAlice;
        }
        return !isAlice;
    }
};