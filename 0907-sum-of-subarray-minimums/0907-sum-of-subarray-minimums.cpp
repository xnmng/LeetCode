// https://youtu.be/9-TXIVEXX2w
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        auto n{static_cast<int>(arr.size())};
        stack<int> s1;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        long ans{0};
        int index;
        for (auto i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] >= arr[i]) {
                right[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        stack<int> s2;
        for (auto i = n-1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] > arr[i]) {
                left[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        // for (auto i : left) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (auto i : right) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        for (long i = 0; i < n; ++i) {
            ans += arr[i] * (i - left[i]) * (right[i] - i);
            ans %= static_cast<int>(1e9+7);
        }
        return ans;
    }
};

// [71,55,82,55]