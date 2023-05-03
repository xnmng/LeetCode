class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        auto i{1};
        auto j{1};
        while (i+j <= bound) {
            while (i+j <= bound) {
                s.insert(i+j);
                j *= y;
                if (j == 1) break;
            }
            i *= x;
            j = 1;
            if (i == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};

// 2
// 1
// 10