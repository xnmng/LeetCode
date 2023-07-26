class Solution {
private:
    bool helper(vector<int>& dist, double hour, int speed) {
        auto count{0.0};
        for (auto& i : dist) {
            if (count > hour) return false;
            count = ceil(count);
            count += 1.0 * i / speed;
        }
        // if (speed == 2) cout << count << "\n";
        return count <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // if (dist.size()-1 > hour) return -1;
        auto low{1};
        auto high{INT_MAX};
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (helper(dist, hour, mid)) {
                // cout << mid << " is true\n";
                high = mid;
            } else {
                // cout << mid << " is false\n";
                low = mid + 1;
            }
        }
        return low == INT_MAX ? -1 : low;
    }
};
// [1,1]
// 1.0