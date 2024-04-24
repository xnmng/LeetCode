class Solution {
public:
    // do some sort of prefix sum calculation
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map<int,int> mp; // <complement, frequency>
        mp[0] = 1;
        int cur = 0; // each bit represents a char's parity
        int temp; // for checking for complements
        for (char c : word) {
            cur ^= (1 << (c - 'a'));
            ans += mp[cur]; // if we have exact complement (mp[cur] ^ cur == 0), add it
            // if (isPowOf2(cur)) ++ans;
            // need to go through every possible "1-bit different" mask!
            // (not just up to cur mask)
            for (int i = 0; i < 10; ++i) {
                // note: the bit in cur DOES NOT need to be set to 1 to add!
                ans += mp[cur ^ (1 << i)];
            }
            ++mp[cur];
        }
        return ans;
    }
    
    bool isPowOf2(int i) {
        bool ans = false;
        while (i > 0) {
            if (ans && i % 2 == 1) return false;
            ans |= (i % 2 == 1);
            i /= 2;
        }
        return ans;
    }
};