class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++count;
        }
        // if string has odd number of vowels, alice will remove entire string and win
        if (count % 2 == 1) return true;

        // if string does not contain any vowels, alice loses immediately
        if (count == 0) return false;

        // if string contains even number of vowels, alice removes an odd number of vowels, 
        // leaving an odd number of vowels. 
        // bob removes an even number of vowels, and we are left with an odd number of vowels.
        // alice removes the entire remainder and wins.
        return true;
    }
};