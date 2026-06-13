class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        ans.reserve(words.size());
        int weight;
        for (auto& w : words) {
            weight = 0;
            for (char c : w) {
                weight = (weight + weights[c - 'a']) % 26;
            }
            ans += 'z' - weight;
        }
        return ans;
    }
};