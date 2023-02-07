class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        pair<int,int> f1{-1, 0};
        pair<int,int> f2{-1, 0};
        auto left{0};
        auto right{0};
        auto ans{0};
        while (right < fruits.size()) {
            if (f1.first == fruits[right]) ++f1.second;
            else if (f2.first == fruits[right]) ++f2.second;
            else {
                ans = max(ans, f1.second + f2.second);
                while (f2.second > 0 && f1.second > 0 && right > left) {
                    if (f1.first == fruits[left]) --f1.second;
                    else if (f2.first == fruits[left]) --f2.second;
                    ++left;
                }
                if (f1.second == 0) {
                    f1.first = fruits[right];
                    f1.second = 1;
                }
                else if (f2.second == 0) {
                    f2.first = fruits[right];
                    f2.second = 1;
                }
            }
            ++right;
            // cout << left << " " << right << "\n";
            // cout << f1.first << " " << f1.second << " " << f2.first << " " << f2.second << "\n\n";
        }
        ans = max(ans, f1.second + f2.second);
        return ans;
    }
};
// [3,3,3,1,2,1,1,2,3,3,4]