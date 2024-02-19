class Solution {
public:
    // solve it using both simultaneous equations:
        // 4x + 2y = tomatoSlices
        // x + y = cheeseSlices
        // 2x + 2y = 2 * cheeseSlices
        // 2y = 2 * cheeseSlices - 2x
        // 
        // 4x + 2 * cheeseSlices - 2x = tomatoSlices
        // 2x + 2 * cheeseSlices = tomatoSlices
        //
        // 2x = tomatoSlices - 2 * cheeseSlices
        // x = (tomatoSlices - 2 * cheeseSlices) / 2
        // y = cheeseSlices - x
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices < 2 * cheeseSlices  
            || tomatoSlices > 4 * cheeseSlices
            || tomatoSlices % 2 == 1) return {};

        int totalJumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
        int totalSmall = cheeseSlices - totalJumbo;
        return {totalJumbo, totalSmall};
    }
};