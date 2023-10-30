class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int abits = 0;
            int bbits = 0;
            int acpy = a;
            int bcpy = b;
            while (acpy > 0) {
                abits += acpy % 2;
                acpy /= 2;
            }
            while (bcpy > 0) {
                bbits += bcpy % 2;
                bcpy /= 2;
            }
            if (abits == bbits) return a < b;
            return abits < bbits;
        });
        return arr;
    }
};