class Solution {
public:
    // binary search for the answer
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 0;
        int high = INT_MAX;
        int mid;
        while (low < high) {
            mid = high - (high - low) / 2;
            if (check(position, m, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    
    // check if a gap of at least x is possible
    bool check(vector<int>& position, int m, int x) {
        int prev = position[0];
        --m;
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - prev >= x) {
                --m;
                prev = position[i];
            }
            if (m == 0) break;
        }
        return m == 0;
    }
};