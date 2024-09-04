class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        // cout << "cols=" << cols << "\n";
        int x = 0;
        int y = 0;
        int next = 1;
        string ans;
        while (x * cols + y < n) {
            // cout << x << " " << y << "\n";
            ans += encodedText[x * cols + y];
            // cout << "add " << encodedText[x * cols + y] << "\n";
            ++x;
            ++y;
            if (x == rows) {
                x = 0;
                y = next;
                ++next;
            }
        }
        while (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};