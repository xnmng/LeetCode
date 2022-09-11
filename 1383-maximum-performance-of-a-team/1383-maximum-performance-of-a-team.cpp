class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for (auto i = 0; i < n; ++i) {
            v.emplace_back(efficiency[i], speed[i]);
        }
        sort(v.begin(), v.end(), 
            [](pair<int,int> a, pair<int,int> b) {
                if (a.first == b.first) return a.second > b.second;
                return a.first > b.first;
            }    
        );
        // for (auto i : v) {
        //     cout << i.first << "," << i.second << " ";
        // }
        // cout << "\n";
        priority_queue<int, vector<int>, greater<int>> pq; // <type, underlying container, sort function>
        long sum{0}; // maximum sum is 10^10 > 2^31
        long ans{0}; // maximum peroformance is 2^63 > 10^18 > 2^31
        for (auto [e, s] : v) {
            pq.push(s);
            sum += s;
            while (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            // cout << sum << " " << e << " " << sum * e << "\n";
            ans = max(ans, sum * e);
        }
        return ans % static_cast<int>(1e9 + 7);
    }
};