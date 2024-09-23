class Solution {
public:
    // sliding window, maintain counts of alternating colours 
    // 1 group of size k should have k-1 adjacent differences; set count to 1 initially for easy comparison
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 1;
        int n = colors.size();
        int ans = 0;
        for (int i = 1; i < n + k; ++i) {
            // cout << i << " " << i % n << " " << (i-1) % n << " " << (i >= k) << " " << (i-k) % n << " " << (i-k+1) % n << "\n";
            // cout << i << " " << count << "\n";
            if (count == k) ++ans;
            if (colors[i % n] != colors[(i-1) % n]) ++count;
            if (i >= k && colors[(i-k) % n] != colors[(i-k+1) % n]) --count;
        }
        
        return ans;
    }
};