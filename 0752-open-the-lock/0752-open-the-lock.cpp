// TODO: learn how to implement bidirectional BFS
class Solution {
public:
    // minimum steps -> use BFS!
    // math is tedious, avoid! e.g. 9009 % 10 is NOT 9009 !!!
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s(deadends.begin(), deadends.end());
        s.reserve(10000);
        // edge case (deadends contains initial positon)
        if (s.find("0000") != s.end()) return -1;
        queue<string> q;
        q.push("0000");
        queue<string> next;
        int ans = 0;
        string cur;
        string temp;
        
        unordered_map<char, char> nextChar = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };
        unordered_map<char, char> prevChar = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };
        
        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (cur == target) return ans;
                if (s.find(cur) != s.end()) continue;
                s.insert(cur);
                for (int i = 0; i < 4; ++i) {
                    temp = cur;
                    temp[i] = nextChar[temp[i]];
                    if (s.find(temp) == s.end()) next.push(temp);
                    temp = cur;
                    temp[i] = prevChar[temp[i]];
                    if (s.find(temp) == s.end()) next.push(temp);
                }
            }
            ++ans;
            swap(q, next);
        }
        return -1;
    }
};