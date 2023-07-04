class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for (auto i = 1; i <= n; ++i) {
            if (i % 3 != 0 && i % 5 != 0) {
                ans[i-1] = to_string(i);
            } 
            if (i % 3 == 0) ans[i-1] += "Fizz";
            if (i % 5 == 0) ans[i-1] += "Buzz";
        }
        return ans;
    }
};