class Solution {
public:
    int findComplement(int num) {
        unsigned int i = 1;
        while (i <= num) i *= 2;
        return i - 1 - num;
    }
};