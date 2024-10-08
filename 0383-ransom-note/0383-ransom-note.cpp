class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26, 0);
        for (auto i : ransomNote) {
            ++v[i - 'a'];
        }
        int count = ransomNote.size();
        for (auto i : magazine) {
            --v[i - 'a'];
            if (v[i - 'a'] >= 0) --count;
            if (count == 0) return true;
        }

        return false;
    }
};