class Solution {
public:
    int countPairs(vector<int>& nums) {
        // sort to take care of the case where digits are not in ascending order
        // affects leading zero (e.g. process 1023 then 213, no match. process 213 then 1023, match)
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp; // frequency map
        int ans = 0;
        for (auto num : nums) {
            string str = to_string(num);
            int n = str.size();
            // only check unique combinations
            unordered_set<int> s;
            s.insert(num); // if num is only 1 digit, double loop will not hit
            // first swap
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    swap(str[i], str[j]);
                    s.insert(stoi(str));
                    // second swap
                    for (int x = 0; x < n; ++x) {
                        for (int y = x+1; y < n; ++y) {
                            swap(str[x], str[y]);
                            s.insert(stoi(str));
                            swap(str[x], str[y]);
                        }
                    }
                    swap(str[i], str[j]);
                }
            }
            
            for (auto i : s) {
                ans += mp[i];
            }
            ++mp[num];
        }
        return ans;
    }
};
// [3,3,20,3,3,13,13,13,3,3,12,8,3,3,3,3,4]