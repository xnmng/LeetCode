class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        k = min(static_cast<int>(profits.size()), k);
        priority_queue<int> pq;     // profits for each project sorted in ascending order
        vector<pair<int,int>> v;    // (capital, profits) for each project
        v.reserve(profits.size());
        for (auto i = 0; i < profits.size(); ++i) {
            v.emplace_back(capital[i], profits[i]);
        }
        sort(v.begin(), v.end());
        auto index{0};
        while (k > 0) {
            for (; index < v.size(); ++index) {
                if (v[index].first <= w) {
                    pq.push(v[index].second);
                } else break;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
            --k;
        }
        return w;
    }
};

// 1
// 0
// [1,2,3]
// [1,1,2]