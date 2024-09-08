class Solution {
public:
    string convertDateToBinary(string date) {
        stringstream ss(date);
        string cur;
        int curNum;
        string temp;
        string ans = "";
        while (getline(ss, cur, '-')) {
            curNum = stoi(cur);
            temp = "";
            if (!ans.empty()) ans += '-';
            while (curNum > 0) {
                temp = (char)('0' + curNum % 2) + temp;
                curNum /= 2;
            }
            ans += temp;
        }
        return ans;
    }
};