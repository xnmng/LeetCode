class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        return n * (n+1) / 2 - 2 * (m * (n / m) * ((n / m) + 1) / 2);
        // n / m := number of ints divisible by m
            
            
            // 3 = 1 * 3
            
            // 6 = 2 * 3
            
            // 9 = 3 * 3
            
            // 12 = 4 * 3
            
            // 3 * (4 * 5 / 2) = 30
    }
};