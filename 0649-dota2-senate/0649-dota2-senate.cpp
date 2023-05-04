// the "best strategy" for a senator is to ban the next closest opponent senator
// instead of searching for the next closest opponent senator, 
// store both in their respective queues and track their index (i.e. their turn)
// for the smaller index, they come first and will ban the other senator
// add to queue their new turn (i.e. current turn + n)

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