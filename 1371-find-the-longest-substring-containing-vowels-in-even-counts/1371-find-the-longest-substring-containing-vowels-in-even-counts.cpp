class Solution {
public:
    // since we only care about even counts and we only have 5 vowels (<= 32bits),
    // we can use a bitmask to represent the state (5 bits)
    // 
    // go through each element and compute the state for [s[0],s[i]].
    // if the state is zero, all vowels are even and we can update our ans 
    // (to i+1; 0-indexed array)
    // (no need to use max cause i+1 will be the best answer so far)
    //
    // if the state doesnt exist in the umap, add it
    // (we want to maintain smallest index for a given state to 'match' with 
    // to compute our answer in the event the best answer is from [s[x], s[i]] 
    // where x != 0)
    int findTheLongestSubstring(string s) {
        unordered_map<char,int> mp{{'a', 1}, {'e', 2}, {'i', 3}, {'o', 4}, {'u', 5}};
        unordered_map<int,int> prev{{0, 0}};
        int state = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.find(s[i]) != mp.end()) {
                state ^= (int) pow(2,mp[s[i]]);
            }
            if (state == 0) {
                ans = i+1;
            }
            else if (prev.find(state) == prev.end()) {
                prev[state] = i;
            } else {
                ans = max(ans, i - prev[state]);
            }
        }
        return ans;
    }
};