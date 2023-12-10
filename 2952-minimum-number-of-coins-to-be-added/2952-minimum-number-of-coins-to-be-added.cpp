class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        int cur = 0; // largest value we are able to currently obtain i.e. [1, cur]
        int index = 0;
        if (coins[0] == 1) {
            ++cur;
            ++index;
        }
        while (index < coins.size()) {
            if (cur >= target) break;
            /*
                if we are able to currently form combinations [1,..., k]
                and we need to add another coin, 
                the best coin we could add is of value k+1
                as this would expand the combinations to [1,..., 2k+1]
                
                when should we add another coin?
                when we are currently able to form combinations [1,..., k]
                and the next coin we process is greater than k+1
                (i.e. adding this next coin will cause our combinations to become 
                2 intervals)
            */
            while (coins[index] > cur + 1) {
                // cout << cur << "\n";
                ++ans;
                if (cur == 0) ++cur;
                else cur = 2 * cur + 1;
            }
            cur += coins[index];
            ++index;
        }
        while (cur < target) {
            // cout << cur << "\n";
            ++ans;
            if (cur == 0) ++cur;
            else cur = 2 * cur + 1;
        }
        return ans;
    }
};

// [15,1,12]
// 43


