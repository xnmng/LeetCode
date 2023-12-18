class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest1 = INT_MIN;
        int largest2 = INT_MIN;
        int smallest1 = INT_MAX;
        int smallest2 = INT_MAX;
        for (int i : nums) {
            if (i > largest1) {
                largest2 = largest1;
                largest1 = i;
            } else if (i > largest2) {
                largest2 = i;
            } 
            if (i < smallest1) {
                smallest2 = smallest1;
                smallest1 = i;
            } else if (i < smallest2) {
                smallest2 = i;
            } 
        }
        // cout << largest1 << " " << largest2 << " " << smallest1 << " " << smallest2 << "\n";
        // return 0;
        return (largest1 * largest2) - (smallest1 * smallest2);
    }
};