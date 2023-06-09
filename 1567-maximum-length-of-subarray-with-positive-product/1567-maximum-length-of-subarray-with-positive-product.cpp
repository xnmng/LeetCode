// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/820072/EASY-soultion-with-DRY-RUN-JAVA
class Solution {
public:
    // If we see a 0, set positive and negative to 0
    // If we see a positive number :
    //     Increase positive count
    //     Unless negative == 0, increase negative count
    // If we see a negative number:
    //     swap positive and negative multiplicative results' lengths 
    //     increment negative count
    //     Unless positive == 0, increase positive count
    // In each iteration, ans = max(ans, positive_count)
    int getMaxLen(vector<int>& nums) {
        auto ans{0};
        auto neg{0};
        auto pos{0};
        for (auto& i : nums) {
            if (i == 0) {
                neg = 0;
                pos = 0;
            }
            else if (i > 0) {
                if (neg > 0) ++neg;
                ++pos;
            }
            else { // i < 0
                swap(pos, neg);
                if (pos > 0) ++pos;
                ++neg;
            }
            // cout << pos << " " << neg << "\n";
            ans = max(ans, pos);
        }
        return ans;
    }
};

// [-1,2]