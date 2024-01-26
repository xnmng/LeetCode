class Solution {
public:
    // standard 2 pointer approach; had some struggle implementing
    int longestBeautifulSubstring(string word) {
        int count = 1; // start for loop at 1; count starts at 1
        int comp = 0;
        int ans = 0;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i-1] == word[i]) {
                ++count;
            }
            else if (word[i-1] < word[i]) {
                ++comp;
                ++count;
            } else {
                comp = 0;
                count = 1;
            }
            // we want all a < e < i < o < u; 
            // suffices to check that we have made 4 comparisons to know we have a valid answer
            if (comp == 4) ans = max(ans, count);
        }
        return ans;
    }
};