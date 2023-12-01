class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        auto x1{0};
        auto x2{0};
        auto y1{0};
        auto y2{0};
        while (x1 < word1.size() && y1 < word2.size()) {
            if (word1[x1][x2] == word2[y1][y2]) {
                ++x2;
                ++y2;
            } else {
                return false;
            }
            if (x2 == word1[x1].size()) {
                ++x1;
                x2 = 0;
            }
            if (y2 == word2[y1].size()) {
                ++y1;
                y2 = 0;
            }
        }
        return x1 == word1.size() && y1 == word2.size();
    }
};

// ["abc","d","defg"]
// ["abcddef"]