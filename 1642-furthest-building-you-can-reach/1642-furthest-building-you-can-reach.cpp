class Solution {
public:
    // ------------------------------------
    // MIN-HEAP APPRAOCH; USE LADDERS FIRST
    // ------------------------------------
    // https://youtu.be/35Z60cfjgKA?si=toVH7Pc0LWyDQeUT
    // (pq is a min-heap; i.e. smallest at the root)
    // use ladders first, until we cant anymore (i.e. when pq.size() > ladders)
    // then, use bricks for each smallest positive jump
    // note: could also use a multiset as opposed to min-heap pq
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // top of pq will be smallest element
        // can also do the 'trick'; push negative value, remember to multiply by -1 when popping from pq
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        int diff;
        for (int i = 0; i < n-1; ++i) {
            diff = heights[i+1] - heights[i];
            if (diff > 0) {
                pq.push(diff);
                if (pq.size() > ladders) {
                    // no need to check that pq is non-empty since we always push earlier above
                    bricks -= pq.top();
                    pq.pop();
                }
            }
            // (insufficient ladders + bricks)
            // unable to progress further than index i
            if (bricks < 0) return i;
        }
        
        // at this point in the code, 
        // we know we were able to reach till the end
        return n-1;
    }
    
//     // -----------------------------------
//     // MAX-HEAP APPROACH; USE BRICKS FIRST
//     // -----------------------------------
//     // https://leetcode.com/problems/furthest-building-you-can-reach/discuss/918761/C++Python3-Priority-Queue
//     // use a max-heap pq; i.e. largest at the root
//     // use bricks first, until we cant then we use ladders
//     // assuming each step we use bricks, if we cant then we 'swap' our ladder
//     // with the biggest brick cost step so far
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         // top of pq will be largest element
//         priority_queue<int> pq;
//         int n = heights.size();
//         int diff;
//         for (int i = 0; i < n-1; ++i) {
//             diff = heights[i+1] - heights[i];
//             if (diff > 0) {
//                 // use brick first
//                 bricks -= diff;
//                 pq.push(diff);
//                 // if bricks are insufficient, replace bricks with a ladder
//                 if (bricks < 0) {
//                     --ladders;
//                     // here, we are guaranteed to replace the largest step 
//                     // from the set of steps {0->1, ... , i->i+1} (IMPORTANT!)
//                     bricks += pq.top();
//                     pq.pop();
//                     // if we still have insufficient bricks, 
//                     // or we dont even have any ladders, 
//                     // this is the furthest we can go,
//                     // and we can early return
//                     if (bricks < 0 || ladders < 0) return i;
//                 }
//             }
//         }
// 
//         // at this point in the code, 
//         // we know we were able to reach till the end
//         return n-1;
//     }
    
//     // ----------------------
//     // BINARY SEARCH APPROACH (LESS EFFICIENT SOLUTION)
//     // ----------------------
//     // https://leetcode.com/problems/furthest-building-you-can-reach/discuss/2177311/C++-Binary-Search
//     // since there exists a given index i which we can reach given bricks and ladders,
//     //      (i.e. [T, ... T,F, ... ,F] for some >= 0 number of F's)
//     // we could also binary search for the answer
//     // however, time complexity is O(n * (logn)^2)
//     // (logn for binary search iteratons, each iteration takes O(nlogn) time)
//     //
//     // helper function can either be implemented using max or min heap; both are fine
//     // (see below solutions if need clarification)
//     // (here its implemented using min heap)
//     bool helper(vector<int>& heights, int bricks, int ladders, int mid) {
//         // store largest n elements
//         priority_queue<int, vector<int>, greater<int>> pq;
//         int diff;
//         for (int i = 0; i < mid; ++i) {
//             diff = heights[i+1] - heights[i];
//             if (diff > 0) {
//                 pq.push(diff);
//                 if (pq.size() > ladders) {
//                     bricks -= pq.top();
//                     pq.pop();
//                 }
//                 if (bricks < 0) return false;
//             }
//         }
//         return true;
//     }
//
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         int n = heights.size();
//         int left = 0;
//         int right = n-1;
//         while (left < right) {
//             int mid = right - (right - left) / 2;
//             // check if we are able to reach the mid index
//             if (helper(heights, bricks, ladders, mid)) {
//                 left = mid;
//             } else {
//                 right = mid-1;
//             }
//         }
//         return left;
//     }
    
    // ---------------------
    // DP APPROACH (TLE/MLE)
    // ---------------------
    // dp should be possible, but 3d DP on (index, bricks, ladders), 
    // which will either TLE/MLE based on the input size
    // i.e. index <= 10^5, bricks <= 10^9, ladders <= 10^5
};