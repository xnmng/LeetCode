class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> source;
        for (auto& path : paths) {
            source.insert(path[0]);
        }
        for (auto& path : paths) {
            if (source.find(path[1]) == source.end()) return path[1];
        }
        return ""; // should not happen
    }
};