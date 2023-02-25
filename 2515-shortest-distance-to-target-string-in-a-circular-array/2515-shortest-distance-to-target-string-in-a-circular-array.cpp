class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        if (words[startIndex] == target) return 0;
        auto n{words.size()};
        auto prev{(startIndex - 1 + n) % n};
        auto next{(startIndex + 1) % n};
        auto d{1};
        while (prev != next) {
            // cout << d << " " << words[prev] << " " << words[next] << "\n";
            if (words[prev] == target || words[next] == target) return d;
            prev = (prev - 1 + n) % n;
            next = (next + 1) % n;
            ++d;
        }
        if (words[prev] == target) return d;
        return -1;
    }
};
// ["ibkgecmeyx","jsdkekkjsb","gdjgdtjtrs","jsdkekkjsb","jsdkekkjsb","jsdkekkjsb","gdjgdtjtrs","msjlfpawbx","pbgjhutcwb","gdjgdtjtrs"]
// "pbgjhutcwb"
// 0
