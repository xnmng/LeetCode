class Solution {
public:
    // iteratively build string in groups of 3 digits (0 - 999) using helper function
    // add qualifier (e.g. Thousand) when necessary
    string numberToWords(int num) {
        // edge case
        if (num == 0) return "Zero";
        
        string ans;
        int count = 0;
        while (num != 0) {
            int base = num % 1000;
            string str = helper(base);
            if (!str.empty()) {
                if (count == 0) ans = helper(base);
                else if (count == 1) 
                    ans = helper(base) + " Thousand" + (ans.empty() ? "" : " ") + ans;
                else if (count == 2) 
                    ans = helper(base) + " Million" + (ans.empty() ? "" : " ") + ans;
                else if (count == 3) 
                    ans = helper(base) + " Billion" + (ans.empty() ? "" : " ") + ans;
            }

            ++count;
            num /= 1000;
        }
        return ans;
    }
    
    string helper(int num) {
        // empty string as padding
        vector<string> ones {
            "", "One", "Two", "Three", "Four", "Five", 
            "Six", "Seven", "Eight", "Nine", "Ten", 
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
            "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", 
            "Seventy", "Eighty", "Ninety"};
        
        int hundreds = num / 100;
        num %= 100;
        string ans = "";
        if (hundreds > 0) {
            ans += ones[hundreds] + " Hundred";
        }
        if (num < 20) {
            if (ans.empty()) ans = ones[num];
            else {
                if (num > 0) ans += " " + ones[num];
            }
        }
        else {
            int digit = num % 10;
            if (ans.empty()) ans = tens[num / 10];
            else {
                if (num > 0) ans += " " + tens[num / 10];
            }
            if (digit != 0) {
                ans += " " + ones[digit];
            }
        }
        return ans;
    }
};
// 100
// 101
// 1000
// 1000000