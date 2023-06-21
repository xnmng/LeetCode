class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
        vector<int> ans(pref.size());
        ans[0] = pref[0];
        for (auto i = 1; i < pref.size(); ++i) {
            ans[i] = pref[i] ^ pref[i-1];
        }
        return ans;
    }
};