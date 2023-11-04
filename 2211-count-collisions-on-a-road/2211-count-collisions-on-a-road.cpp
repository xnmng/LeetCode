class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        bool hasPrev = false;
        int count = 0; // number of cars moving to the right
        for (auto i : directions) {
            switch (i) {
                case 'R':
                    hasPrev = true;
                    ++count;
                    break;
                case 'S':
                    hasPrev = true;
                    ans += count;
                    count = 0;
                    break;
                case 'L':
                    if (hasPrev) {
                        ans += count + 1;
                        count = 0;
                    }
                    break;
            }
        }
        return ans;
    }
};