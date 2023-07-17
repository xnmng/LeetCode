class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        auto target{static_cast<int>(pow(2, req_skills.size()))-1};
        unordered_map<string,int> mp;
        for (auto i : req_skills) {
            mp[i] = pow(2, mp.size());
        }
        
        // trim input; ignore people with no skills and remove duplicate people with same skills
        int cur;
        unordered_map<int,int> p; // (skills, index)
        for (auto i = 0; i < people.size(); ++i) {
            cur = 0;
            for (auto& j : people[i]) {
                cur += mp[j];
            }
            if (cur > 0) p[cur] = i;
        }
        
        unordered_map<int,vector<int>> dp;
        // prevent rehash; 
        //     insertions below will not cause iterator to invalidate as no rehash will happen
        dp.reserve(target+1);
        dp[0] = {};
        for (auto& [skills, index] : p) {
            for (auto itr = dp.begin(); itr != dp.end(); ++itr) {
                cur = itr->first | skills;
                if (dp.find(cur) == dp.end() 
                    || dp[cur].size() > 1 + dp[itr->first].size()) {
                    dp[cur] = itr->second;
                    dp[cur].emplace_back(index);
                }
            }
        }
        return dp[target];
    }
};