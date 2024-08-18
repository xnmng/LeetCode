class Solution {
public:
    // https://www.youtube.com/watch?v=1pj2a5bmziY
    // O(n) time, O(n) space
    int nthUglyNumber(int n) {
        vector<int> v{1};
        int ptr2 = 0;
        int ptr3 = 0;
        int ptr5 = 0;
        while (v.size() != n) {
            int next = min(v[ptr2] * 2, min(v[ptr3] * 3, v[ptr5] * 5));
            v.emplace_back(next);
            // we might have duplicates
            if (v.back() == v[ptr2] * 2) ++ptr2;
            if (v.back() == v[ptr3] * 3) ++ptr3;
            if (v.back() == v[ptr5] * 5) ++ptr5;
        }
        return v.back();
    }
};