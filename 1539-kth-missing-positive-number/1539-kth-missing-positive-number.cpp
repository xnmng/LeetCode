class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int next{1};
        for (auto i : arr) {
            if (i == next) ++next;
            else if (k > i - next) {
                k -= i - next;
                next = i+1;
            }
            else break;
            // cout << next << " " << k << "\n";
        }
        return next + k - 1;
    }
};