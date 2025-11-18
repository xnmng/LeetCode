class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = 0;
        int n = bits.size();
        while (index < n - 1) {
            if (bits[index] == 0) ++index;
            else if (bits[index] == 1) index += 2;
        }
        if (index == n) return false;
        return true;
    }
};