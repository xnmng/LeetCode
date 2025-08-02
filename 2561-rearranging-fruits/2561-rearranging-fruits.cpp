class Solution {
public:
    // if (count1[x] + count2[x]) is odd, return -1
    //
    // keep track of the minimum element in both baskets (will be useful later)
    //
    // initialize a vector, keep all the elements needed to move inside
    // (e.g. if one basket has k extras, we need to move k/2 of them over)
    // 
    // how should we move the fruits? 2 ways:
    // 1. directly swap, cost is min(x, y) (swap smallest with largest to keep cost minimal)
    // 2. swap with minimum element (swap x with minimum, then minimum with y),
    // cost is 2 * minimum
    //
    // sort the vector, focus on the smallest half of elements and perform the calculation
    //
    // O(nlogn) time, O(n) space
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<long long,int> mp; // +ve -> basket1, -ve -> basket2 extra
        long long minimum = INT_MAX;
        for (long long i : basket1) {
            ++mp[i];
            minimum = min(minimum, i);
        }
        for (long long i : basket2) {
            --mp[i];
            minimum = min(minimum, i);
        }
        vector<long long> v;
        for (auto [k, val] : mp) {
            if (abs(val) % 2 == 1) return -1;
            for (int i = 0; i < abs(val) / 2; ++i) {
                v.emplace_back(k);
            }
        }
        sort(v.begin(), v.end());
        // for (int i : v) cout << i << " ";
        long long ans = 0;
        for (int i = 0; i < v.size() / 2; ++i) {
            ans += min(v[i], 2 * minimum);
        }
        return ans;
    }
};