class Solution {
public:
    // greedily map highest freq to earliest char on numpad
    // total of 8 numbers we can map to
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (auto i : word) {
            ++freq[i - 'a']; 
        }
        // sort in descending order of freq
        sort(freq.rbegin(), freq.rend());
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) break;
            ans += ((i / 8) + 1) * freq[i];
        }
        return ans;
    }
};