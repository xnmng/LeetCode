class Solution {
public:
    string frequencySort(string s) {
        // count frequency of each char
        vector<int> v(75, 0);
        for (auto i : s) {
            ++v[i - '0'];
        }
        
        // 'emit' (freq, char) pairs and sort, construct answer and return
        vector<pair<int, int>> v2;
        v2.reserve(52);
        for (auto i = 0; i < 10; ++i) { // only iterate through char index
            if (v[i] > 0) v2.emplace_back(v[i], i);
        }
        for (auto i = 17; i < 43; ++i) { // only iterate through char index
            if (v[i] > 0) v2.emplace_back(v[i], i);
        }
        for (auto i = 49; i < 75; ++i) { // only iterate through char index
            if (v[i] > 0) v2.emplace_back(v[i], i);
        }
        sort(v2.begin(), v2.end(), greater<pair<int,int>>());
        string ans;
        for (auto& [freq, offset] : v2) {
            ans += string(freq, offset + '0');
        }
        return ans;
    }
};

// "AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz0011223344556677889"
// "2a554442f544asfasssffffasss"