// https://leetcode.com/problems/design-browser-history/discuss/674300/Two-Stacks-vs.-List
// keep a max index instead of resizing
class BrowserHistory {
private:
    vector<string> v;
    int curindex;
    int maxindex;
public:
    BrowserHistory(string homepage) : curindex{0}, maxindex{0} {
        v.push_back(homepage);
    }
    
    void visit(string url) {
        if (curindex + 1 == v.size()) {
            v.push_back(url);
        }
        else {
            v[curindex+1] = url;
        }
        ++curindex;
        maxindex = curindex;
    }
    
    string back(int steps) {
        if (curindex - steps < 0) {
            curindex = 0;
        }
        else curindex -= steps;
        return v[curindex];
    }
    
    string forward(int steps) {
        auto index{min(maxindex, curindex + steps)};
        curindex = index;
        return v[curindex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */