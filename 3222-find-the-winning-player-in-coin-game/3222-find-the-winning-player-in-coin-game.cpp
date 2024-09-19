class Solution {
public:
    string losingPlayer(int x, int y) {
        int count = min(x, y/4);
        // count == 0, alice lose, bob win
        // count == 1, bob lose, alice win
        // count == 2, alice lose, bob win
        /// ...
        return count % 2 == 0 ? "Bob" : "Alice";
    }
};