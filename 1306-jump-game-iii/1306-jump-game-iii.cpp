class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        unordered_set<int> v;
        q.push(start);
        // cout << "ok\n";
        while(!q.empty()) {
            int cur = q.front();
            // cout << cur << "\n";
            q.pop();
            if (cur >= arr.size() || cur < 0) {
                continue;
            }
            if (arr[cur] == 0) {
                return true;
            }
            if (v.find(cur) != v.end()) {
                continue;
            } else {
                v.insert(cur); 
                q.push(cur + arr[cur]);
                q.push(cur - arr[cur]);
            }
        }
        return false;
    }
};