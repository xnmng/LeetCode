class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        vector<pair<int,char>> v{
            {a, 'a'},
            {b, 'b'},
            {c, 'c'},
        };
        update(v);
        // for (auto [a,b] : v) cout << a << " " << b << "\n";
        int next;
        while (true) {
            next = 0;
            if (!isValid(ans, v[next].second)) {
                next = 1;
            }
            else if (!isValid(ans, v[next].second)) {
                next = 2;
            }
            if (v[next].first == 0) break;
            ans += v[next].second;
            --v[next].first;
            update(v);
        }
        
        return ans;
    }
    
    // sorts vector in descending order of freq
    void update(vector<pair<int, char>>& v) {
        if (v[0].first <= v[1].first && v[0].first <= v[2].first) {
            swap(v[0], v[2]);
        }
        else if (v[1].first <= v[0].first && v[1].first <= v[2].first) {        
            swap(v[1], v[2]);
        }
        if (v[0].first <= v[1].first) {
            swap(v[0], v[1]);            
        }
    }
    
    // returns true if c can be placed next to ans
    bool isValid(string& ans, char c) {
        if (ans.size() < 2) return true;
        if (*ans.rbegin() == c && *(ans.rbegin() + 1) == c) return false;
        return true;
    }
};