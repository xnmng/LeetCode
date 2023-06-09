class Solution {
private:
    bool check(vector<int>& v) {
        auto count{0};
        for (auto i : v) {
            if (i != 0 && count == 0) {
                count = i;
            }
            if (i != 0 && count != i) return false;
        }
        return true;
    }
public:
    bool equalFrequency(string word) {
        vector<int> v(26, 0);
        for (auto& i : word) {
            ++v[i - 'a'];
        }
        for (auto i = 0; i < 26; ++i) {
            if (v[i] > 0) {
                --v[i];
                if (check(v)) return true;
                ++v[i];
            }
        }
        return false;
    }
};