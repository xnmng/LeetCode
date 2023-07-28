class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for (auto& i : trips) {
            mp[i[1]] += i[0];
            mp[i[2]] -= i[0];
        }
        for (auto& [k,v] : mp) {
            capacity -= v;
            if (capacity < 0) return false;
        }
        return true;
    }
};