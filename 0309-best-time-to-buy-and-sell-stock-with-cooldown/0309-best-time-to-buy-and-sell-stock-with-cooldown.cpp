class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto buy{0};
        auto sell{INT_MIN};
        auto cooldown{INT_MIN};
        int temp;
        for (auto i : prices) {
            temp = buy;
            buy = max(buy, cooldown);
            cooldown = max(cooldown, sell + i);
            sell = max(sell, temp - i);
        }
        return max(buy, cooldown);
    }
};

// b  0     
// s  -1
// cd 0  

// buy -> sell -> cooldown -> buy

// buy[i] = max(buy[i-1], cd[i-1])
// sell[i] = max(sell[i-1], buy[i-1] - arr[i])
// cd[i] = max(sell[i-1] + arr[i], cd[i-1])