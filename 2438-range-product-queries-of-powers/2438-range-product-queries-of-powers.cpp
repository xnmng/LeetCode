class Solution {
public:
    // n is an int, max no. of bits is 32
    // can brute force
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans;
        ans.reserve(m);
        vector<int> powers;
        int next = 1;
        while (n > 0) {
            if (n % 2 == 1) powers.emplace_back(next);
            next *= 2;
            n /= 2;
        }
        long cur;
        long modulo = 1e9 + 7;
        for (auto& q : queries) {
            // cout << q[0] << " " << q[1] << "\n";
            cur = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                cur = (cur * powers[i]) % modulo;
            }
            ans.emplace_back(cur);
        }
        return ans;
    }
};