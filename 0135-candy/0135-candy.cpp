// https://leetcode.com/problems/candy/discuss/2234434/C++-oror-O(n)-Time-O(1)-Space-oror-Full-Explanation

/*
O(n) time 2 pass, O(n) space:
iterate across left to right and right to left,
    The first loop makes sure children with a higher rating get more candy than its left neighbor, 
    the second loop makes sure children with a higher rating get more candy than its right neighbor. 
    At last add the total number of candies.
    
O(n) time 1 pass, O(1) space:
peaks and valleys
*/

/*
notice that we dont need to come up with the actual candy distribution, 
only need to count the total number of candies

two equal neighbours may have any number of candies
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        int i = 1;
        int peak = 0;
        int valley = 0;
        while (i < n) {
            // we process pairs of "/\"
            if (ratings[i-1] == ratings[i]) {
                ++i;
                continue;
            }
            int peak = 0;
            int valley = 0;
            while (i < n && ratings[i-1] < ratings[i]) {
                ++peak;
                ans += peak;
                ++i;
            }
            // if ratings[i-1] == ratings[i] 
            // candy resets to 1 as two equal neighbours may have any number of candies
            while (i < n && ratings[i-1] > ratings[i]) {
                ++valley;
                ans += valley;
                ++i;
            }
            // we added peak and valley value, subtract the min
            // ok to end with "/" because valley will be 0 (i.e. line below does nothing)
            ans -= min(peak, valley);
        }
        return ans + n; // each child should have at least 1 candy
    }
};
// [1,3,2,2,1]
// [1,3,4,5,2]