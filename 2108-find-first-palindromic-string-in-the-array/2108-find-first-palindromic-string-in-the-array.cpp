class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto i : words) {
            auto left{0};
            auto right{i.size()-1};
            while (left < right) {
                if (i[left] == i[right]) {
                    ++left;
                    --right;
                } else break;
            }
            if (left >= right) return i;
        }
        return "";
    }
};