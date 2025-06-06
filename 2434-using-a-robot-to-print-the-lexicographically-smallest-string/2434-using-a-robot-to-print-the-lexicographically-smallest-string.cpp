class Solution {
public:
    // greedily append the smallest chars, the rest defer to stack
    string robotWithString(string str) {
        vector<int> v(26, 0);
        for (char c : str) ++v[c - 'a'];
        
        int n = str.size();
        string ans;
        ans.reserve(n);
        stack<char> s;
        char minChar = 'a';

        for (char c : str) {
            s.push(c);
            --v[c - 'a'];

            while (minChar != 'z' && v[minChar - 'a'] == 0) ++minChar;

            while (!s.empty() && s.top() <= minChar) {
                ans += s.top();
                s.pop();
            }
        }

        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }

        return ans;
    }
};