// https://leetcode.com/problems/find-the-winner-of-an-array-game/solution/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int largest = *max_element(arr.begin(), arr.end());
        int cur = arr[0];
        int count = 0;
        for (auto i = 1; i < arr.size(); ++i) {
            if (cur > arr[i]) {
                ++count;
            } else {
                cur = arr[i];
                count = 1;
            }
            
            if (count == k || cur == largest) {
                break;
            }
        }
        return cur;
    }
};