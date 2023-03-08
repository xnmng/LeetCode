class Solution {
private:
    bool helper(vector<int>& piles, int& h, int& speed) {
        auto count{0};
        for (auto i : piles) {
            count += i / speed;
            if (i % speed != 0) ++count;
        }
        return count <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left{1};
        int right{INT_MAX};
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (helper(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};