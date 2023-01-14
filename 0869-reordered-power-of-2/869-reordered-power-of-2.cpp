class Solution {
    bool helper(vector<int> v, int n) {
       while (n != 0) {
            --v[n % 10];
            n /= 10;
        }
        for (auto i : v) {
            if (i != 0) return false;
        }
        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> count(10, 0);
        while (n != 0) {
            ++count[n % 10];
            n /= 10;
        }
        for (auto i = 0; i < 31; ++i) {
            if (helper(count, static_cast<int>(pow(2, i)))) {
                return true;
            }
        }
        return false;
    }
};