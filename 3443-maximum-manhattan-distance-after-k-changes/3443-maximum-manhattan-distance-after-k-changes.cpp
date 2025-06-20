class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int temp;
        vector<int> count(4, 0); // N, S, E, W
        for (char c : s) {
            if (c == 'N') ++count[0];
            else if (c == 'S') ++count[1];
            else if (c == 'E') ++count[2];
            else if (c == 'W') ++count[3];

            // check each possible direction
            //
            // alternatively, take max of both directions (up/down, left/right)
            // then try to add at most k to it
            // since we are replacing, the effect is x2
            temp = max(count[0], count[1]) + max(count[2], count[3])
                - min(count[0], count[1]) - min(count[2], count[3]);
            temp += 2 * min(k, min(count[0], count[1]) + min(count[2], count[3]));
            ans = max(ans, temp);
        }

        return ans;
    }
};