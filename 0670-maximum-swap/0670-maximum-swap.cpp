class Solution {
public:
    // iterate in reverse
    //
    // find largest digit to the right
    // if we are at a digit that is not the largest digit to the right, 
    // check that this digit is smaller 
    //
    // if we cant find any swap pair, return initial number
    //
    // O(n) 1 pass O(logn) space
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        // store indexes
        int left = -1;
        int right = -1;
        // largest digit and its index
        char digit = '0';
        int digitIndex = -1;
        for (int i = n-1; i >= 0; --i) {
            // we have found a better digit
            if (digit < numStr[i]) {
                digit = numStr[i];
                digitIndex = i;
            }
            // we have found a swap pair
            else if (numStr[i] < digit) {
                left = i;
                right = digitIndex;
            }
        }
        if (left == -1) return num;
        // cout << left << " " << numStr[left] << " " << right << " " << numStr[right] << "\n";
        swap(numStr[left], numStr[right]);
        return stoi(numStr);
    }
};
// 98368