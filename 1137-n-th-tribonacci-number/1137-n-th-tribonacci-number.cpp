class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        auto t0{0};
        auto t1{1};
        auto t2{1};
        auto count{2};
        int temp;
        while (count != n) {
            temp = t2 + t1 + t0;
            swap(t1, t0);
            swap(t2, t1);
            swap(temp, t2);
            ++count;
        }
        return t2;
    }
};