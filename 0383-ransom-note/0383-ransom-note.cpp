class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for (auto i : ransomNote) {
            ++mp[i];
        }
        int count = ransomNote.size();
        for (auto i : magazine) {
            --mp[i];
            if (mp[i] >= 0) --count;
            if (count == 0) return true;
        }

        return false;
    }
};