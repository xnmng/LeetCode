class Solution {
public:
    // sort using map, generate ans vector and return
    // can reduce down to O(k) space (where k is the number of unique elements in arr if we traverse twice)
    // add the unique elements, set the rank, generate ans vector (1 pass each)
    // O(N) time (3 pass), O(k) space
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp; // value to index
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            mp[arr[i]];
        }
        vector<int> ans;
        ans.reserve(n);
        int rank = 1;
        for (auto& [k,v] : mp) {
            v = rank;
            ++rank;
        }
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(mp[arr[i]]);
        }
        return ans;
    }
    
    // O(N) time, O(N) space
    // vector<int> arrayRankTransform(vector<int>& arr) {
    //     map<int,vector<int>> mp; // value to index
    //     int n = arr.size();
    //     for (int i = 0; i < n; ++i) {
    //         mp[arr[i]].emplace_back(i);
    //     }
    //     vector<int> ans(n);
    //     int rank = 1;
    //     for (auto [k,v] : mp) {
    //         for (int i : v) {
    //             ans[i] = rank;
    //         }
    //         ++rank;
    //     }
    //     return ans;
    // }
};