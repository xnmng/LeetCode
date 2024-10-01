class Solution {
public:
    // use 2 maps; 1 to track ball -> colour, 1 to track colour -> ball_count
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();
        ans.reserve(n);
        unordered_map<int,int> mp1; // ball to colour
        unordered_map<int,int> mp2; // colour to balls with colour
        for (int i = 0; i < n; ++i) {
            int ball = queries[i][0];
            int colour = queries[i][1];
            int oldColour = mp1[ball];
            if (mp1[ball] != 0) {
                --mp2[oldColour];
                if (mp2[oldColour] == 0) {
                    mp2.erase(oldColour);
                }
            }
            mp1[ball] = colour;
            ++mp2[colour];
            ans.emplace_back(mp2.size());
        }
        return ans;
    }
};