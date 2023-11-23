class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for (auto& i : knowledge) {
            mp[i[0]] = i[1];
        }
        string ans;
        string temp;
        bool inReplace = false;
        for (auto i : s) {
            if (i == '(') {
                inReplace = true;
            } else if (i == ')') {
                inReplace = false;
                if (mp.find(temp) == mp.end()) {
                    ans += '?';
                } else {
                    ans += mp[temp];
                }
                temp = "";
            } else {
                if (inReplace) {
                    temp += i;
                } else {
                    ans += i;
                }
            }
        }
        return ans;
    }
};