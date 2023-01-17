class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for (auto i : arr) {
            ++mp[i];
        }
        vector<int> freq;
        for (auto& [k,v] : mp) {
            freq.push_back(v);
        }
        sort(freq.begin(), freq.end());
        for (auto i = 0; i < freq.size(); ++i) {
            if (k - freq[i] >= 0) {
                k -= freq[i];
            } else {
                return freq.size() - i;
            }
        }
        return 0;
    }
};