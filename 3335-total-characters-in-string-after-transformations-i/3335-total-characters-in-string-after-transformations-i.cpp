class Solution {
public:
    // we only want the length, not the actual string
    // since we know the transition of each char
    // we can simply track the freq of each char then check the size at the end
    //
    // for each transition, we can 

    // TODO: why doesnt this work?
    // int lengthAfterTransformations(string s, int t) {
    //     int modulo = 1e9 + 7;
    //     unordered_map<int,long> mp;
    //     for (char c : s) {
    //         ++mp[c - 'a'];
    //     }
    //     int zindex = 25;
    //     for (int i = 0; i < t; ++i) {
    //         mp[(zindex + 1) % 26] = (mp[(zindex + 1) % 26] + mp[zindex]) % modulo;
    //         mp[(zindex + 2) % 26] = (mp[(zindex + 2) % 26] + mp[zindex]) % modulo;
    //         mp[zindex] = 0;
    //         zindex = (zindex + 25) % 26;
    //     }

    //     int ans = 0;
    //     for (auto& [k,v] : mp) {
    //         // cout << k << " " << v << "\n";
    //         ans = (ans + v) % modulo;
    //     }
    //     return ans;
    // }

    int lengthAfterTransformations(string s, int t) {
        int modulo = 1e9 + 7;
        vector<long> freq(26, 0);
        for (char c : s) {
            ++freq[c - 'a'];
        }
        vector<long> next;
        for (int i = 0; i < t; ++i) {
            next = vector<long>(26, 0);
            for (int j = 0; j < 25; ++j) {
                next[j+1] = freq[j];
            }
            next[0] = freq.back();
            next[1] = (next[1] + freq.back()) % modulo;
            swap(next, freq);
        }

        int ans = 0;
        for (long i : freq) {
            ans = (ans + i) % modulo;
        }
        return ans;
    }
};