class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        auto ans{1};
        while (memory1 >= ans || memory2 >= ans) {
            if (memory2 > memory1) {
                memory2 -= ans;
            } else memory1 -= ans;
            // cout << memory1 << " " << memory2 << "\n";
            ++ans;
        }
        return {ans, memory1, memory2};
    }
};