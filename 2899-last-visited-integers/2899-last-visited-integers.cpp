class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> v;
        vector<int> ans;
        int count = 0;
        for (auto& i : words) {
            if (i == "prev") {
                ++count;
                if (v.size() >= count) ans.emplace_back(v[v.size() - count]);
                else {
                    ans.emplace_back(-1);
                }
            } else {
                count = 0;
                v.emplace_back(stoi(i));
            }
        }
        return ans;
    }
};