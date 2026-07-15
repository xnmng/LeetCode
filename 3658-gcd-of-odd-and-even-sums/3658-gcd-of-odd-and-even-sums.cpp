class Solution {
public:
    // sum of all odd numbers is n^2
    // sum of all even numbers is n(n+1)
    // 
    // 2 consecutive integers are coprime (gcd(n, n+1) = 1)
    // gcd(n^2, n(n+1)) = n * gcd(n, n+1) = n * 1 = n
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};