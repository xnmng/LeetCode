class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        for (auto i = 0; i < arr.size(); ++i) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        queue<int> next;
        q.push(0);
        int cur;
        int ans{0};
        unordered_set<int> s;
        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (cur + 1 == arr.size()) return ans;
                if (mp.find(arr[cur]) != mp.end()) {
                    for (auto i : mp[arr[cur]]) {
                        next.push(i);
                        s.insert(i);
                    }
                    mp.erase(arr[cur]);
                }
                if (cur + 1 < arr.size() && s.find(cur + 1) == s.end()) {
                    next.push(cur + 1);
                    s.insert(cur + 1);
                }
                if (cur - 1 >= 0 && s.find(cur - 1) == s.end()) {
                    next.push(cur - 1);
                    s.insert(cur - 1);
                }
            }
            ++ans;
            swap(q, next);
        }
        return ans;
    }
};

// [11,22,7,7,7,7,7,7,7,22,13]