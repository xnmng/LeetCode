class Solution {
public:
    int passThePillow(int n, int time) {
        time %= n * 2 - 2;
        if (time < n) return 1+time;
        else return n - (time - n + 1);
    }
};
