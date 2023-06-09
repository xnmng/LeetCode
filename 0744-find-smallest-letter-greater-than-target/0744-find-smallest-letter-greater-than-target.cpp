// https://leetcode.com/problems/find-smallest-letter-greater-than-target/discuss/110027/C++-Solution-O(log-n)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) return letters.front();
        auto left{0};
        auto right{static_cast<int>(letters.size()-1)};
        while (left < right) {
            auto mid{left + (right - left) / 2};
            if (target < letters[mid]) right = mid;
            else left = mid+1;
        }
        return letters[left];
    }
};

// ["c","f","j"]
// "j"