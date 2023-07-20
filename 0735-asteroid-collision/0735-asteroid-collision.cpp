class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        bool add;
        for (auto& i : asteroids) {
            add = true;
            while (!ans.empty() && ans.back() > 0 && i < 0) {
                if (abs(ans.back()) < abs(i)) {
                    ans.pop_back();
                } else {
                    if (abs(ans.back()) == abs(i)) {
                        ans.pop_back();
                    }
                    add = false;
                    break;
                }
            }
            if (add) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
// [-2,-1,1,2]