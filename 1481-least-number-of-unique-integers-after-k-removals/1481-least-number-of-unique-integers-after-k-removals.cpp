class Solution {
public:
    // // count frequencies, sort then greedily remove
    // // O(nlogn) time, O(n) space (max of n unique elements in vector)
    // int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    //     unordered_map<int,int> mp;
    //     for (auto i : arr) {
    //         ++mp[i];
    //     }
    //     vector<int> freq;
    //     for (auto& [k,v] : mp) {
    //         freq.push_back(v);
    //     }
    //     sort(freq.begin(), freq.end());
    //     for (auto i = 0; i < freq.size(); ++i) {
    //         if (k - freq[i] >= 0) {
    //             k -= freq[i];
    //         } else {
    //             return freq.size() - i;
    //         }
    //     }
    //     return 0;
    // }
    
    // O(n) time, O(n) space solution:
    // instead of emitting the frequencies of each number then sorting,
    // we know that if we have n numbers, we have a maximum frequency of n
    // instead of storing frequencies of each number, we can have a vector of size n+1,
    // where each index i will store the number of ints that have frequency i
    // (e.g. v[2] will store the number of ints with frequency 2)
    // we can then avoid sorting (which is nlogn) and instead traverse the vector v,
    // updating till we get the ans (doing all of this in O(n) time)
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for (auto i : arr) {
            ++mp[i];
        }
        int n = arr.size();
        vector<int> freq(n+1, 0);
        for (auto& [k,v] : mp) {
            ++freq[v];
        }
        int ans = mp.size();
        int count; // number of unique integers removed in this iteration
        for (int i = 1; i < n+1; ++i) {
            if (freq[i] > 0) {
                count = min(freq[i], k / i);
                if (count == 0) break;
                ans -= count;
                k -= count * i;
            }
        }
        return ans;
    }
    

};