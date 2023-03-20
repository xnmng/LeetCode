class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool canPlace{false};
        auto k{flowerbed.size()};
        for (int i = 0; i < k; ++i) {
            canPlace = true;
            if (flowerbed[i] == 1) continue;
            if (i - 1 >= 0 && flowerbed[i-1] == 1) canPlace = false;
            if (i + 1 < k && flowerbed[i+1] == 1) canPlace = false;
            if (canPlace) {
                --n;
                flowerbed[i] = 1;
            }
        }
        // for (auto i : flowerbed) cout << i << " ";
        // cout << "\n";
        return n <= 0;
    }
};

// [1,0,0,0,0,1]
// 2