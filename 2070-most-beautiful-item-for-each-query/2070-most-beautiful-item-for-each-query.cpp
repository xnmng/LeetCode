class Solution {
public:
    // note: we can only select ONE item
    // sort (see below) items by price, then update items to store only bestBeauty so far
    // binary search for answer for each query
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int m = queries.size();
        int n = items.size();
        vector<int> ans;
        ans.reserve(queries.size());
        sort(items.begin(), items.end(),
            [](vector<int>& a, vector<int>& b) { 
                // handle the case where 2 items have same price but one has lower beauty;
                // put the higher beauty one first (so the below loop wont have any bugs)
                if (a[0] == b[0]) {
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            });
        for (int i = 1; i < n; ++i) {
            items[i][1] = max(items[i][1], items[i-1][1]);
        }
        for (int i = 0; i < m; ++i) {
            ans.emplace_back(helper(items, queries[i]));
        }
        return ans;
    }

    int helper(vector<vector<int>>& items, int price) {
        int left = 0;
        int right = items.size() - 1;
        int mid;
        int ans = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (price >= items[mid][0]) {
                ans = max(ans, items[mid][1]);
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};