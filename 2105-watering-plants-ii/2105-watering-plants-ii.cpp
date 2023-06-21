class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        auto left{0};
        auto right{static_cast<int>(plants.size()-1)};
        auto curA{capacityA};
        auto curB{capacityB};
        auto ans{0};
        while (left <= right) {
            if (left == right) {
                if (max(curA, curB) < plants[left]) ++ans;
            } else {
                if (curA < plants[left]) {
                    ++ans;
                    curA = capacityA - plants[left];
                } else {
                    curA -= plants[left];
                }
                if (curB < plants[right]) {
                    ++ans;
                    curB = capacityB - plants[right];
                } else {
                    curB -= plants[right];
                }
            }
            ++left;
            --right;
        }
        return ans;
    }
};