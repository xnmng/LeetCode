class SummaryRanges {
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value) {
        int left = value, right = value;
        auto small_entry = intervals.upper_bound(value);
        if (small_entry != intervals.begin()) {
            auto max_entry = small_entry;
            --max_entry;
            if (max_entry->second >= value) {
                return;
            }
            if (max_entry->second == value - 1) {
                left = max_entry->first;
            }
        }
        if (small_entry != intervals.end() && small_entry->first == value + 1) {
            right = small_entry->second;
            intervals.erase(small_entry);
        }
        intervals[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;
        for (const auto& p : intervals) {
            answer.push_back({p.first, p.second});
        }
        return answer;
    }
};

// https://youtu.be/FavoZjPIWpo
// class SummaryRanges {
// private:
//     vector<vector<int>> range;
//     unordered_set<int> s;
// public:
//     SummaryRanges() {}
    
//     void addNum(int val) {
//         if (!s.insert(val).second) return;
//         if (val + 1 == range[0][0]) {
//             range[0][0] = val;
//             return;
//         }
//         auto n{range.size()};
//         if (range[n-1][1] + 1 == val) {
//             range[n-1][1] = val;
//             return;
//         }
//         vector<vector<int>> v{val, val};
//         for (auto i = 0; i < range.size(); ++i) {
            
//         }
//     }
    
//     vector<vector<int>> getIntervals() {
//         return range;
//     }
// };

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */