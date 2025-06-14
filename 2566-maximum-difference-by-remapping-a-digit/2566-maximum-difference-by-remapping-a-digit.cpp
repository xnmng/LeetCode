class Solution {
public:
    int minMaxDifference(int num) {
        string maximum = to_string(num);
        string minimum = to_string(num);
        size_t pos = maximum.find_first_not_of('9');
        if (pos != string::npos) {
            char a = maximum[pos];
            replace(maximum.begin(), maximum.end(), a, '9');
        }
        char b = minimum[0];
        replace(minimum.begin(), minimum.end(), b, '0');
        return stoi(maximum) - stoi(minimum);
    }
};