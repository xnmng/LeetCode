class Solution {
private:
    // (real, imaginary)
    pair<int,int> parse(string& s) {
        auto real{0};
        auto isRealNeg{false};
        auto imaginary{0};
        auto isImNeg{false};

        auto isReal{true};
        for (auto i : s) {
            if (i == 'i') continue;
            if (i == '+') isReal = false;
            else if (isReal) {
                if (i == '-') isRealNeg = true;
                else {
                    real *= 10;
                    real += i - '0';
                }
            } else { // parsing imaginary number
                if (i == '-') isImNeg = true;
                else {
                    imaginary *= 10;
                    imaginary += i - '0';
                }
            }
        }
        if (isRealNeg) real *= -1;
        if (isImNeg) imaginary *= -1;
        return {real, imaginary};
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        auto n1{parse(num1)};
        auto n2{parse(num2)};
        // cout << n1.first << " " << n1.second << "\n";
        // cout << n2.first << " " << n2.second << "\n\n";
        auto real{n1.first * n2.first + -1 * n1.second * n2.second};
        auto im{n1.first * n2.second + n2.first * n1.second};
        // cout << n1.first * n2.first << " " << n1.first * n2.second 
        //     << " " << n2.first * n1.second << " " << -1 * n1.second * n2.second << "\n";
        return to_string(real) + '+' + to_string(im) + 'i';
    }
};