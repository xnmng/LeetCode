class Solution {
public:
    // note: each apple[i] is number of apples, 
    // not pack the entire apple[i] into one box
    // (completely different problem!)
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int sum = 0;
        int index = 0;
        for (auto i : apple) sum += i;
        for (auto i : capacity) {
            sum -= i;
            if (sum <= 0) break;
            ++index;
        }

        return index + 1; // 0-based indexing
    }
};