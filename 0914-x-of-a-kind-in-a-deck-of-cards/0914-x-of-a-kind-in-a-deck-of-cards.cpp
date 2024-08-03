class Solution {
public:
    // all numbers must have gcd > 1
    // https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/solution/
    // https://codility.com/media/train/10-Gcd.pdf
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for (auto i : deck) ++mp[i];
        int ans = 0;
        for (auto& [k,v] : mp) {
            ans = gcd(ans, v);
            if (v == 1 || ans == 1) return false;
        }
        return true;
    }
    
    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
};