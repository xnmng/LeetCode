class Solution {
public:
    // note: line sweep with map is also possible (still same TC)
    // O(nlogn) time (due to sort), O(sort)
    int countDays(int days, vector<vector<int>>& meetings) {
        // if you use vector<int> without the reference, it copies the vector and might cause TLE!
        // (recall that vector uses heap memory to store the elements)
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
           if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        // similar to end, manually add start since 1 is a valid day
        int ans = meetings[0][0] - 1;
        int prev = meetings[0][1];
        for (auto& i : meetings) {
            // -1 to handle case where prev = k and i[0] = k+1, should be 0, not 1
            ans += max(i[0] - prev - 1, 0);
            prev = max(prev, i[1]);
            if (prev >= days) break;
        }
        // no need -1 here since days is a valid day
        ans += max(days - prev, 0);
        return ans;
    }
};
// 8
// [[3,4],[4,8],[2,5],[3,8]]
// 57
// [[3,49],[23,44],[21,56],[26,55],[23,52],[2,9],[1,48],[3,31]]