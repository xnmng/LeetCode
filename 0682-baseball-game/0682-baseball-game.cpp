class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        vector<int> v;
        for (auto& i : ops) {
            if (i == "C") {
                ans -= v.back();
                v.pop_back();
            } else if (i == "D") {
                v.emplace_back(2 * v.back());
                ans += v.back();
            } else if (i == "+") {
                v.emplace_back(*v.rbegin() + *(v.rbegin() + 1));
                ans += v.back();
            } else {
                v.emplace_back(stoi(i));
                ans += v.back();
            }
        }
        return ans;
    }
};