class Solution {
    vector<string> mapping{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        string cur{""};
        auto ans{0};
        for (auto w : words) {
            cur = "";
            for (auto c : w) {
                cur += mapping[c - 'a'];
            }
            if (s.insert(cur).second) ++ans;
        }
        return ans;
    }
};