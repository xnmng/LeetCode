class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool isFlush{true};
        auto prev{suits[0]};
        for (auto i : suits) {
            if (prev != i) {
                isFlush = false;
                break;
            }
        }
        if (isFlush) return "Flush";
        unordered_map<int,int> mp;
        auto count{0};
        for (auto i : ranks) {
            ++mp[i];
            count = max(count, mp[i]);
        }
        if (count >= 3) return "Three of a Kind";
        if (count == 2) return "Pair";
        return "High Card";
    }
};