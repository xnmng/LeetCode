// https://leetcode.com/problems/number-of-flowers-in-full-bloom/solution/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        for (auto& i : flowers) {
            starts.emplace_back(i[0]); // flower blooms at t = t1
            ends.emplace_back(i[1]+1); // flower actually stops blooming at t = (t2+1)
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> ans;
        
        // e.g. we want to insert 5 into this arr
        // [4, 5(1), 6]
        //     ^     ^
        // (^ indicates index to insert; everything after ^ to the right gets 'shifted right')
        // leftmost insertion index (include equals) -> use lower_bound
        // [4, 5(2), 5(1), 6]
        //
        // rightmost insertion index -> use upper_bound
        // [4, 5(1), 5(2), 6]
        for (auto i : people) {
            // find the first index greater than i -> k1 == number of flowers bloomed 
            // find the first index greater than i -> k2 == number of flowers that have already stopped
            auto left = upper_bound(starts.begin(), starts.end(), i);
            auto right = upper_bound(ends.begin(), ends.end(), i);
            ans.emplace_back(distance(starts.begin(), left) - distance(ends.begin(), right));
        }
        return ans;
    }
};
/*
    Note that a flower = [start, end] stops blooming at end + 1, not end. 
    
    There are two ways we can handle this. 
    
    We can either binary search on end for the leftmost insertion index 
    (since we want to include all flowers with end equal to the current time), 
    or we can assemble ends using end + 1 for each flower.
*/