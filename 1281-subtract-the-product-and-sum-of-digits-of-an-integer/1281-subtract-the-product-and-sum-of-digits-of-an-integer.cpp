class Solution {
public:
    int subtractProductAndSum(int n) {
        if (n == 0) return 0;
        
        auto product{1};
        auto sum{0};
        while (n != 0) {
            product *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return product - sum;
    }
};