// https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/

// For lower_bound(): 
// Initialise the startIndex as 0 and endIndex as N – 1.
// Compare K with the middle element(say arr[mid]) of the array.
// If the middle element is greater equals to K then update the endIndex as a middle index(mid).
// Else Update startIndex as mid + 1.
// Repeat the above steps until startIndex is less than endIndex.
// After all the above steps the startIndex is the lower_bound of K in the given array.

// For upper_bound(): 
// Initialise the startIndex as 0 and endIndex as N – 1.
// Compare K with the middle element(say arr[mid]) of the array.
// If the middle element is less than equals to K then update the startIndex as middle index + 1(mid + 1).
// Else Update endIndex as mid.
// Repeat the above steps until startIndex is less than endIndex.
// After all the above steps the startIndex is the upper_bound of K in the given array.

// not sure why my implementation of binary search is incorrect...

class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> mp; // {timestamp, value}
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (mp[key].empty() || (!mp[key].empty() && mp[key][0].first > timestamp)) return "";
        // auto it{upper_bound(mp[key].begin(), mp[key].end(), pair<int,string>(timestamp, ""), 
        //     [](pair<int,string> a, pair<int,string> b) {
        //         return a.first < b.first;
        //     }
        // )};
        // return prev(it)->second;
        
        auto left{0};
        auto right{mp[key].size()-1};
        while (left < right) {
            auto mid{left + (right - left)/2};
            if (mp[key][mid].first <= timestamp) left = mid+1;
            else right = mid;
        }
        // cout << left << "\n";
        if (left < mp[key].size() && mp[key][left].first <= timestamp) ++left;
        // cout << left << " " << mp[key][left].first << " " << mp[key][left].second << "\n";
        return mp[key][left-1].second;
    }
};

// ["TimeMap","set","set","get","get","get","get","get"]
// [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */