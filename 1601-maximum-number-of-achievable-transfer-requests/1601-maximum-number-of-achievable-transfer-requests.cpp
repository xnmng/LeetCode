class Solution {
private:
    void dfs(vector<vector<int>>& requests, int index, int count, vector<int>& state, int& ans) {
        bool allZero{true};
        for (auto i : state) {
            if (i != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) ans = max(ans, count);
        if (index == requests.size()) return;
        ++state[requests[index][0]];        
        --state[requests[index][1]];
        dfs(requests, index+1, count+1, state, ans);
        --state[requests[index][0]];        
        ++state[requests[index][1]];        
        dfs(requests, index+1, count, state, ans);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> state(n, 0);
        auto ans{0};
        dfs(requests, 0, 0, state, ans);
        return ans;
    }
};

// 3
// [[1,2],[1,2],[2,2],[0,2],[2,1],[1,1],[1,2]]