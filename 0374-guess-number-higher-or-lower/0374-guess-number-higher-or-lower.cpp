/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        auto low{1};
        auto high{n};
        int mid;
        while (true) {
            mid = low + (high - low) / 2;
            if (guess(mid) == 0) break;
            guess(mid) > 0 ? low = mid + 1 : high = mid;
        }
        return mid;
    }
};