class Solution {
public:
    // based on the problem, our goal is to maximize the score
    // we notice that it would make sense to greedily flip smaller tokens face-up,
    // and flip larger tokens face-down
    // this allows us to maintain a larger score, which ideally will allow us to flip more
    // tokens face-up to obtain a larger score
    //
    // 2 pointer approach:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int cur = 0;
        int ans = 0;
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                ++cur;
                ans = max(ans, cur);
                ++left;
                // instead of maintaining both ans and cur variables,
                // can also just maintain ans and check that left < right 
                // (i.e. there is at least 1 more token left to be played)
            } else if (ans > 0) {
                power += tokens[right];
                --cur;
                --right;
            } else break;
        }
        return ans;
    }
};

// [71,55,82]
// 54