class Solution {
public:
    // simulate is also possible, but not necessary
    //
    // since we stop once tickets[k] reaches 0, and we go in round robin order,
    // any index < k will be depleted max tickets[k] times
    // any index > k will be depleted max tickets[k]-1 times
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = tickets[k];
        int n = tickets.size();
        for (int i = 0; i < k; ++i) {
            ans += min(tickets[i], tickets[k]);
        }
        for (int i = k+1; i < n; ++i) {
            ans += min(tickets[i], tickets[k]-1);
        }
        return ans;
    }
};
// [84,49,5,24,70,77,87,8]
// 3

