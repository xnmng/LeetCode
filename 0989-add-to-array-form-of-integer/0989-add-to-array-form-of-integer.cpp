class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        auto index{0};
        while (k != 0) {
            // cout << k << " " << index << "\n";
            // for (auto i : num) cout << i << " ";
            // cout << "\n";
            if (index < num.size()) {
                k += num[index];
                num[index] = k % 10;
            } else {
                num.push_back(k % 10);
            }
            k /= 10;
            ++index;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};