class Solution {
public:
    // note: both digits cannot have leading zeroes!
    // maximum: replace first digit from the left that is not '9' with '9'
    // e.g. 123 -> 923, 987 -> 997
    // 
    // minimum: 
    // if first digit is not 1, replace all first digit to '1'
    // if first digit is 1, replace first digit from the left that is not '1' with '0'
    // e.g. 876 -> 176, 123 -> 103
    int maxDiff(int num) {
        string maximum = to_string(num);
        string minimum = to_string(num);
        int max_digit = ' '; // replace this digit in maximum to '9'
        for (char& c : maximum) {
            if (max_digit == ' ' && c != '9') {
                max_digit = c;
            }
            if (c == max_digit) c = '9';
        }

        int min_digit = ' '; // replace this digit in maximum to '1'
        int first_digit = ' ';
        int replace_digit = '1';
        for (char& c : minimum) {
            if (first_digit == ' ') {
                first_digit = c;
                if (first_digit == '1') replace_digit = '0';
                else min_digit = first_digit;
            }
            if (min_digit == ' ' && c != '0' && c != first_digit) {
                min_digit = c;
            }
            if (c == min_digit) c = replace_digit;
        }

        // cout << maximum << " " << minimum << "\n";
        return stoi(maximum) - stoi(minimum);
    }
};