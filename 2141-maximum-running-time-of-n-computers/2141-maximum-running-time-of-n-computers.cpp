// https://youtu.be/Jc5aAtzDqmg
class Solution {
private:
    bool helper(int n, vector<int>& batteries, long long val) {
        auto count{0};
        auto cur{0ll};
        auto index{0};
        while (index < batteries.size() && count < n) {
            if (batteries[index] > val) {
                ++count;
            } else {
                cur += batteries[index];
            }
            if (cur >= val) {
                ++count;
                // we have more batteries than computers; 
                // can "pick and choose" aka not bottlenecked by number of batteries
                cur -= val;
            }
            ++index;
        }
        return count == n;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left{INT_MAX};
        long long right{0ll};
        for (auto& i : batteries) {
            right += i;
            left = min(left, static_cast<long long>(i));
        }
        right /= n;
        long long mid;
        while (left < right) {
        /*  
            the difference comes when we are selecting the middle element in an even sized search space.
            Imagine you have your search space of two elements
            so if you do right-(right-left)/2 you are basically selecting the second element as your middle element                 so if you don't find an ans for that middle element you need to shift your right pointer to mid -1. 
            otherwise you will get TLE.

            Similarly , if you choose left + (right-left)/2 you are selecting the first element as your middle                       element and now you should move your left pointer to mid+1 , so that you don't end up getting TLE
            if you don't do so you will end up getting the same middle element again and again.
        */
            mid = right - (right - left) / 2;
            if (helper(n, batteries, mid)) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        return left;
    }
};
// 3
// [10,10,3,5]