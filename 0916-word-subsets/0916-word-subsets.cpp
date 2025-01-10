class Solution {
public:
    // since a has to match every word b in words2, union every b in words2 to form c
    // then just compare frequencies in a with c
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> v(26,0);
        vector<int> temp(26,0);
        for (auto& i : words2) {
            fill(temp.begin(), temp.end(), 0);
            for (char c : i) {
                ++temp[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                v[i] = max(v[i], temp[i]);
            }
        }

        int n = words1.size();
        bool flag;
        for (int i = 0; i < n; ++i) {
            flag = true;
            fill(temp.begin(), temp.end(), 0);
            for (char c : words1[i]) {
                ++temp[c - 'a'];
            }
            for (int j = 0; j < 26 && flag; ++j) {
                if (temp[j] < v[j]) {
                    flag = false;
                }
            }
            if (flag) ans.emplace_back(words1[i]);
        }
        
        return ans;
    }
};