class Solution {
public:
    // if at the end of our sum biggest digit becomes 0, change it to 1 and emplace back a 0
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int sum;
        for (auto itr = digits.rbegin(); itr != digits.rend(); ++itr) {
            if (carry == 0) break;
            sum = *itr + carry;
            carry = sum / 10;
            *itr = sum % 10;
        }
        if (*digits.begin() == 0 && carry == 1) {
            digits[0] = 1;
            digits.emplace_back(0);
        }
        return digits;
    }
};