// https://leetcode.com/problems/self-crossing/discuss/729133/How-to-explain-to-interviewer-335.-Self-Crossing
// https://leetcode.com/problems/self-crossing/discuss/79142/Java-Solution-based-on-spiral-direction-status
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        
        // TODO: proof of correctness
        
        for (auto i = 3; i < distance.size(); ++i) {
            // east direction intersects with north
            if (i >= 3 
                && distance[i-3] >= distance[i-1] 
                && distance[i-2] <= distance[i]) {
                // cout << "case1\n";
                return true;
            }
            // north direction intersects with north
            if (i >= 4 
                && distance[i-4] < distance[i-2] 
                && distance[i-3] == distance[i-1] 
                && distance[i] + distance[i-4] >= distance[i-2]) {
                // cout << "case2\n";
                return true;
            }
            // west direction intersects with north
            if (i >= 5
                && distance[i-5] < distance[i-3] 
                && distance[i-4] <= distance[i-2] 
                && distance[i-1] + distance[i-5] >= distance[i-3]
                && distance[i-3] >= distance[i-1]
                && distance[i] + distance[i-4] >= distance[i-2]) {
                // cout << "case3\n";
                return true; 
            }
        }
        return false;
    }
};
/*
              Case 1                  Case 2                  Case 3
                b                       b                       b
       +----------------+      +----------------+      +----------------+
       |                |      |                |      |                |
       |                |      |                |      |                |
     c |                | a  c |                | a  c |                | a
       |                |      |                |      |                |    f
       +--------------->|      |                |      |                | <----+
                d       |      |                ^ e    |                |      | e
                               |                |      |                       |
                               +----------------+      +-----------------------+
                                        d                       d
    */

// [1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1]