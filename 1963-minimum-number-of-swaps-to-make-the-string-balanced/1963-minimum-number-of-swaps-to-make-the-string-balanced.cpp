class Solution {
public:
    int minSwaps(string s) {
        auto count{0}; // imbalance count
        for (auto i : s) {
            if (i == '[') ++count;
            else if (i == ']' && count > 0) --count;
        }
        // in 1 swap we can remove at most 2 imbalances
        // e.g. ]]...[[ -> []...[] or ][ -> []
        return (count + 1) / 2;
    }
};
