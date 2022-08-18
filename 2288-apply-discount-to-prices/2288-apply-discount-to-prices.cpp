class Solution {
    bool isPrice(string& p) {
        if (p[0] != '$' || p.size() <= 1) return false;
        for (auto i = 1; i < p.size(); ++i) {
            if (p[i] - '0' < 0 || p[i] - '0' > 9) return false;
        }
        return true;
    }
    
    string applyDiscount(string& s, int discount) {
        long double val{stod(s.substr(1)) * (100 - discount) / 100};
        val = round(val * 100.0) / 100.0;
        return "$" + format(to_string(val));
    }
    
    string format(string s) {
        stringstream ss(s);
        string p1;
        string p2;
        getline(ss, p1, '.');
        getline(ss, p2, '.');
        return p1 + "." + p2.substr(0, 2);
    }
public:
    string discountPrices(string sentence, int discount) {
        string ans{""};
        
        stringstream ss(sentence);
        string cur{""};
        
        while (getline(ss, cur, ' ')) {
            if (isPrice(cur)) {
                cur = applyDiscount(cur, discount);
            }
            
            if (ans.size() != 0) {
                ans += " ";
            }
            ans += cur;
        }
        return ans;
    }
};

// "$76111 ab $6 $"
// 48
// "$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999"
// 5
// because of this test case ^ we need long double