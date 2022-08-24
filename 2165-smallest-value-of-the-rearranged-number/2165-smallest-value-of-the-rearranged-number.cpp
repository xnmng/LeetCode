class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return num; // edge case
        
        bool isNegative{num < 0};
        if (isNegative) {
            num *= -1;
        }
        vector<string> nums;
        auto zeroes{0};
        while (num != 0) {
            if (num % 10 == 0) {
                ++zeroes;
            } else {
                nums.push_back(to_string(num % 10));
            }
            num /= 10;
        }
        string ans{""};
        if (isNegative) {
            sort(nums.begin(), nums.end(), 
                [](string& s1, string& s2) {
                    return s1 > s2;
                }
            );
            for (auto i : nums) {
                ans += i;
            }
            ans += string(zeroes, '0');
        } else {
            sort(nums.begin(), nums.end());
            ans = nums[0];
            ans += string(zeroes, '0');
            for (auto i = 1; i < nums.size(); ++i) {
                ans += nums[i];
            }
        }
        // cout << ans << "\n";
        return isNegative ? -1 * stoll(ans) : stoll(ans);
    }
};

// 0