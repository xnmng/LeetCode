class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1);
        unordered_map<string,int> set1;
        unordered_map<string,int> set2;
        string cur;
        while (getline(ss, cur, ' ')) {
            ++set1[cur];
        }
        
        ss.clear();
        ss.str(s2);

        vector<string> ans;
        while (getline(ss, cur, ' ')) {
            ++set2[cur];
        }
        for (auto& [cur,_] : set1) {
            if (set2[cur] == 0 && set1[cur] == 1) ans.emplace_back(cur);
        }
            for (auto& [cur,_] : set2) {
            if (set1[cur] == 0 && set2[cur] == 1) ans.emplace_back(cur);
        }
        return ans;        
    }
};