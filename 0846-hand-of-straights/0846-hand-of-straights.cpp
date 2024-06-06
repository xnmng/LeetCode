class Solution {
public:
    // TODO: read
    // https://leetcode.com/problems/hand-of-straights/solution/
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int,int> mp;
        for (int i : hand) ++mp[i];
        for (int i : hand) {
            int start = i;
            if (mp[start] == 0) continue;
            while(mp[start - 1] > 0) --start;
            int count = mp[start];
            // cout << "start at " << start << " count " << mp[start] << "\n";
            for (int i = start; i < start + groupSize; ++i) {
                if (mp[i] < count) return false;
                mp[i] -= count;
            }
        }
        return true;
    }
};
// [8,10,12]
// 3