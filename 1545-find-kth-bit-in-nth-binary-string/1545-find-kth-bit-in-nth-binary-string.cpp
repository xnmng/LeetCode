class Solution {
public:
    // recurse to find the kth bit
    // O(n) time O(n) space
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int size = (1 << n) - 1;
                
        // if k is in the left half, recurse
        if (k - 1 < size / 2) return findKthBit(n - 1, k);
        
        // by construction, we know the middle most element is always '1'
        if (k - 1 == (size / 2)) return '1';
        
        // if k is in the left half, recurse and 
        // invert due to definition of right half
        char bit = findKthBit(n - 1, size - k + 1);
        return (bit == '0') ? '1' : '0';
    }
};
// 4
// 12
// 3
// 2