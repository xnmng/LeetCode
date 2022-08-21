class Solution {
    bool matches(string& stamp, string& target, int index) {
        auto count{0};
        for (auto i = 0; i < stamp.size(); ++i) {
            if (target[index + i] == '?') ++count; 
            if (target[index + i] == '?' 
                || target[index + i] == stamp[i]) continue;
            return false;
        }
        return count != stamp.size();
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        queue<int> q;
        
        for (auto i = 0; i <= target.size() - stamp.size(); ++i) {
            if (matches(stamp, target, i)) {
                ans.push_back(i);
                // cout << "ans added " << i << "\n";                
                for (auto j = 0; j < stamp.size(); ++j) {
                    target[i+j] = '?';
                }
            } else {
                q.push(i);
                // cout << "added " << i << "\n";
            }
        }
        // for (auto i : target) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        auto count{0};
        while (!q.empty()) {
            queue<int> next;
            while (!q.empty()) {
                auto n{q.front()};
                q.pop();
                // cout << n << " " << matches(stamp, target, n) << "\n";
                if (matches(stamp, target, n)) {
                    ++count;
                    ans.push_back(n);
                    for (auto i = 0; i < stamp.size(); ++i) {
                        target[i+n] = '?';
                    }
                } else {
                    next.push(n);
                }
            }
            if (count == 0) break;
            q = next;
            count = 0;
        }
        // for (auto i : target) {
            // cout << i << " ";
        // }
        // cout << "\n";
        for (auto i : target) {
            if (i != '?') return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// "oz"
// "ooozz"
// "df"
// "dfdff"
// "zbs"
// "zbzbsbszbssbzbszbsss"