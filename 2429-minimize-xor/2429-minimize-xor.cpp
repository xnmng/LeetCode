class Solution {
public:
    // count bits in num2, set count largest bits in num1 and return the result
    int minimizeXor(int num1, int num2) {
        int count = 0;
        while (num2 > 0) {
            count += num2 % 2;
            num2 /= 2;
        }
        int num1cpy = num1;
        for (int i = 31; i >= 0; --i) {
            if (((1 << i) & num1cpy) > 0) {
                num1cpy = (1 << i) ^ num1cpy;
                --count;
                if (count == 0) break;
            }
        }
        
        // if num1 has less bits set than num2, 
        // greedily set the rest of the bits in x
        int ans = num1cpy ^ num1;
        for (int i = 0; i < 32; ++i) {
            if (count == 0) break;
            if (((1 << i) & ans) == 0) {
                ans = (1 << i) | ans;
                --count;
            }
        }
        return ans;
    }
};