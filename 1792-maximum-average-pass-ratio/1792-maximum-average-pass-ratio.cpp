class Solution {
public:
    // we cannot compare just by the fraction's ratios!
    // e.g. 1/2 vs 1000/2000, should add to 1/2, not 1000/2000!
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            double gainA = (double)(a.first + 1) / (a.second + 1) - (double)a.first / a.second;
            double gainB = (double)(b.first + 1) / (b.second + 1) - (double)b.first / b.second;
            return gainA < gainB;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }

        while (extraStudents > 0) {
            auto [pass, total] = pq.top();
            pq.pop();
            ++pass;
            ++total;
            pq.push({pass, total});
            --extraStudents;
        }

        double ans = 0.0;
        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();
            ans += (double)pass / total;
        }
        return ans / classes.size();
    }
};
