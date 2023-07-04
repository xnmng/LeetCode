class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(32, 0);
        auto isNegative{0};
        auto index{0};
        for (auto& i : nums) {
            if (i < 0) {
                isNegative = (isNegative + 1) % 3;
                i = abs(i) - 1;
            }
            index = 0;
            while (i != 0) {
                v[index] = (v[index] + (i % 2)) % 3;
                i /= 2;
                ++index;
            }
        }
        // for (auto i : v) cout << i << " ";
        // cout << "\n";
        auto ans{0};
        for (auto i = v.rbegin(); i != v.rend(); ++i) {
            ans *= 2;
            ans += *i;
        }
        return isNegative ? (-1 * ans) - 1 : ans;
    }
};
// [-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,-2147483648,2147483645,-814645,2147483645,-216555]