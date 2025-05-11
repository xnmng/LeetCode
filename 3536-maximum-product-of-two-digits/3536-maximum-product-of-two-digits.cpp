class Solution {
public:
    int maxProduct(int n) {
        vector<int> v(10, 0);
        while (n > 0) {
            ++v[n % 10];
            n /= 10;
        }
        int ans = 1;
        int num = 9;
        while (num >= 0) {
            if (v[num] > 0) {
                ans *= num;
                if (ans != num) {
                    break;
                }
                --v[num];
            }
            else --num;
        }
        return ans;
    }
};