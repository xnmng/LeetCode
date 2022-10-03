// my idea: stack O(n) time, O(n) space
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        auto left{0};
        auto right{1};
        auto ans{0};
        auto sum{neededTime[0]};
        auto maxi{neededTime[0]};
        while (right < colors.size()) {
            while (right < colors.size()) {
                if (colors[left] == colors[right]) {
                    // cout << "same " << right << "\n";
                    sum += neededTime[right];
                    maxi = max(maxi, neededTime[right]);
                    ++right;
                } else break;
            }
            if (left + 1 != right) {
                ans += sum;
                ans -= maxi;
            }
            left = right;
            ++right;
            sum = neededTime[left];
            maxi = neededTime[left];
        }
        return ans;
    }
};

// "cddcdcae"
// [4,8,8,4,4,5,4,2]