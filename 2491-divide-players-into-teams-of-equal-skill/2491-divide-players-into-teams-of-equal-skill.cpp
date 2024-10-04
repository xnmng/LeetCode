class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        unordered_map<long long,long long> mp;
        int sum = 0;
        int n = skill.size();
        for (int i : skill) {
            sum += i;
        }
        if (sum % (n / 2) != 0) return -1;
        int goal = sum / (n / 2);
        int count = 0;
        int opp;
        for (int i : skill) {
            if (i > goal) return -1;
            opp = goal - i;
            if (mp[opp] > 0) {
                ans += opp * i;
                --mp[opp];
                --count;
            }
            else {
                ++mp[i];
                ++count;
            }
        }
        if (count > 0) return -1;
        return ans;
    }
};
// [2,2,2,2]