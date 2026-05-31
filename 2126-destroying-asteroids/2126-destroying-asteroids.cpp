class Solution {
public:
    bool asteroidsDestroyed(long mass, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i : arr) {
            if (mass < i) return false;
            mass += i;
        }
        return true;
    }
};