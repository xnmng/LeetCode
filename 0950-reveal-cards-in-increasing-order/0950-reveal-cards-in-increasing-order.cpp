class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        sort(deck.begin(), deck.end(), greater<int>());
        dq.push_back(deck[0]);
        for (auto i = 1; i < deck.size(); ++i) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }
        vector<int> ans;
        while (!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};