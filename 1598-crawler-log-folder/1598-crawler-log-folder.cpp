class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for (auto& i : logs) {
            if (i == "../") {
                count = max(count-1, 0);
            } else if (i != "./") {
                ++count;
            }
        }
        return count;
    }
};