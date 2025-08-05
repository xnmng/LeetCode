class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        bool placed;
        for (int i : fruits) {
            placed = false;
            for (int& j : baskets) {
                if (i <= j) {
                    j = 0;
                    placed = true;
                    break;
                }
            }
            if (!placed) ++ans;
        }
        return ans;
    }
};