class Solution {
public:
    // intuitively such numbers are very sparse, assuming a large range [low, high]
    // since we want the result in sorted order, perhaps dfs isnt a good idea, 
    // and using bfs we can implicitly enforce an ordering
    // run bfs on digits 1-9, add cur to queue only if it will be a potential solution
    // (i.e. last digit is not 9 and cur < high)
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        int cur;
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur >= low && cur <= high) ans.emplace_back(cur);
            if (cur < high && (cur % 10) < 9) {
                q.push(cur * 10 + (cur % 10 + 1));
            }
        }
        return ans;
    }

};