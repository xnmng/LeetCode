class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26) return false;
        vector<int> v(26, 0);
        for (auto i : sentence) ++v[i - 'a'];
        for (auto i : v) {
            if (i == 0) return false;
        }
        return true;
    }
};