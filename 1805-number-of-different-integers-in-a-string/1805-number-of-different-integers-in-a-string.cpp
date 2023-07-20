class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        bool isNum{false};
        string cur;
        for (auto& i : word) {
            if (isdigit(i)) {
                isNum = true;
                if (!cur.empty() || i != '0') cur += i;
            }
            else {
                if (isNum) {
                    s.insert(cur);
                }
                isNum = false;
                cur = "";
            }
        }
        if (isNum) {
            s.insert(cur);
        }
        return s.size();
    }
};
// "167278959591294"