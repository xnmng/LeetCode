// https://en.wikipedia.org/wiki/Digital_root
class Solution {
public:
    int addDigits(int num) {
        if (num <= 9) return num;
        return 1 + (num-1) % 9;
    }
};