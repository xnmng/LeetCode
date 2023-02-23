class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans{0};
        vector<pair<int,int>> v;
        for (auto i = 0; i < nums1.size(); ++i) {
            v.emplace_back(nums2[i], nums1[i]);
        }
        sort(v.begin(), v.end(), greater());
        // for (auto i : v) {
        //     cout << i.first << " " << i.second << "\n";
        // }
        long long sum{0};
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [n2, n1] : v) {
            sum += n1;
            pq.push(n1);
            if (pq.size() > k) {
                sum -= pq.top();
                // cout << pq.top() << "\n";
                pq.pop();
            }
            if (pq.size() == k) {
                // cout << sum << " " << n2 << "\n";
                ans = max(ans, static_cast<long long>(sum * n2));
            }
        }
        return ans;
    }
};

// [2,1,14,12]
// [11,7,13,6]
// 3