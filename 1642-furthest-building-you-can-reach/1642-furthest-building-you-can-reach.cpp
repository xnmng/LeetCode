class Solution {
public:
    // TODO
    // dp should be possible, but 3d DP
    //
    // TODO
    // assuming each step we use bricks, if we cant then we 'swap' our ladder
    // with the biggest brick cost step so far
    //
    // use ladders first, until we cant anymore
    // then use bricks for each smallest positive jump
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
};