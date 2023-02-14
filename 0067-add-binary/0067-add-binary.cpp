class Solution {
public:
    string addBinary(string a, string b) {
        int sum{0};
        int carry{0};
        string res;
        auto aitr{a.rbegin()};
        auto bitr{b.rbegin()};
        while (aitr != a.rend() || bitr != b.rend()) {
            sum = carry;
            carry = 0;
            if (aitr != a.rend()) {
                sum += *aitr - '0';
                ++aitr;
            }
            if (bitr != b.rend()) {
                sum += *bitr - '0';
                ++bitr;
            }
            res += to_string(sum % 2);
            carry = sum / 2;
        }
        if (carry == 1) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};