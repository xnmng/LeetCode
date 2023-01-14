class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky{1e9 <= 1LL * length * width * height 
            || length >= 10000 
            || width >= 10000 
            || height >= 10000};
        bool isHeavy{mass >= 100};
        if (isBulky && isHeavy) return "Both";
        if (isBulky) return "Bulky";
        if (isHeavy) return "Heavy";
        return "Neither";
    }
};

// 10000
// 1
// 1
// 1
// 1000
// 1000
// 1000
// 1000