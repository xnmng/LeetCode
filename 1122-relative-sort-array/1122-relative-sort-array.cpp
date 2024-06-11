class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // key -> index in arr2
        unordered_map<int,int> mp;
        for (int i = 0; i < arr2.size(); ++i) {
            mp[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), 
            [&mp](int a, int b) {
                if (mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
                    return mp.at(a) < mp.at(b);
                }
                if (mp.find(a) == mp.end() 
                    && mp.find(b) != mp.end()) return false;
                else if (mp.find(b) == mp.end() 
                         && mp.find(a) != mp.end()) return true;
                else return a < b;
            });
        return arr1;
    }
};