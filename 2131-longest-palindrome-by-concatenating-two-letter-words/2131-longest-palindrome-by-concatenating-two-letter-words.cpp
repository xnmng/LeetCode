class Solution {
private:
    int opp(int a) {
        return (a % 26 * 26) + (a / 26);
    }
    
    int hash(string& s) {
        return (s[0] - 'a') * 26 + (s[1] - 'a');
    }
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<int,int> mp;
        auto ans{0};
        int val{0};
        bool hasCore{false};
        auto count{0}; // debug
        for (auto& i : words) {
            ++mp[hash(i)];
            ++count;
        }
        // cout << "\n";
        for (auto& [k,v] : mp) {
            // cout << k << " " << v << "\n";
            if (k == opp(k)) {
                if (v % 2 == 1) hasCore = true;
                ans += v/2 * 4;
                continue;
            }
            if (mp.find(opp(k)) == mp.end()) continue;
            ans += 2 * min(mp[opp(k)], v);
        }
        return hasCore ? ans + 2 : ans;
    }
};
// ["oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"]
// ["lc","cl","gg"]
// ["ab","ty","yt","lc","cl","ab"]
// ["cc","ll","xx"]
// ["cc","ll","xx","xx"]
// ["cc","ll","xx","xx","xx"]

// chars the same -> take even number <= v (e.g. 3 take 2, 2 take 2),
// if odd, return ans += 2;