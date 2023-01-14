class Solution {
    int helper(int n) {
        auto ans{0};
        while (n > 0) {
            ans += pow(n % 10, 2);
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) return false;
            s.insert(n);
            n = helper(n);
        }
        return true;
    }
};