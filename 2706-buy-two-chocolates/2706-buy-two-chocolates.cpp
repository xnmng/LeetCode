class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest = INT_MAX;
        int smallest2 = INT_MAX;
        for (int i : prices) {
            if (i < smallest) {
                smallest2 = smallest;
                smallest = i;
            } else if (i < smallest2) {
                smallest2 = i;
            }
        }
        return (smallest2 + smallest) > money ? money : money - smallest - smallest2;
    }
};