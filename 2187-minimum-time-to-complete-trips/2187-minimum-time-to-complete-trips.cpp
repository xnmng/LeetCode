class Solution {
private:
    bool helper(vector<int>& v, int& goal, long long& time) {
        long long count{0};
        for (auto i : v) {
            if (LLONG_MAX - count <= time / i) return true;
            count += time / i;
        }
        return count >= goal;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left{0};
        long long right{LLONG_MAX};
        long long mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (helper(time, totalTrips, mid)) {
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
};

// [39,82,69,37,78,14,93,36,66,61,13,58,57,12,70,14,67,75,91,1,34,68,73,50,13,40,81,21,79,12,35,18,71,43,5,50,37,16,15,6,61,7,87,43,27,62,95,45,82,100,15,74,33,95,38,88,91,47,22,82,51,19,10,24,87,38,5,91,10,36,56,86,48,92,10,26,63,2,50,88,9,83,20,42,59,55,8,15,48,25]
// 4187