class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        int n = dist.size();
        time.reserve(n);
        for (auto i = 0; i < n; ++i) {
            time.emplace_back(1.0 * dist[i] / speed[i]);
            // cout << dist[i] / speed[i] << " ";
        }
        // cout << "\n";
        sort(time.begin(), time.end());
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            if (i >= time[i]) {
                break;
            }
            ++ans;
        }
        return ans;
    }
};