class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq;
        queue<int> dq;
        for (auto i = 0; i < senate.size(); ++i) {
            senate[i] == 'R' ? rq.push(i) : dq.push(i);
        }
        while (!rq.empty() && !dq.empty()) {
            if (rq.front() < dq.front()) {
                rq.push(rq.front() + senate.size());
            }
            else {
                dq.push(dq.front() + senate.size());                
            }
            rq.pop();
            dq.pop();
        }
        return !rq.empty() ? "Radiant" : "Dire"; 
    }
};