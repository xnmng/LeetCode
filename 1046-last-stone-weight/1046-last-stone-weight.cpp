class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 0) return 0;
        if (stones.size() == 1) return stones[0];
        sort(stones.begin(), stones.end());
        auto largest{*stones.rbegin()};
        stones.pop_back();
        auto nextLargest{*stones.rbegin()};
        stones.pop_back();
        if (largest - nextLargest != 0) 
            stones.push_back(largest - nextLargest);
        return lastStoneWeight(stones);
    }
};