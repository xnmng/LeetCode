class StockSpanner {
private:
    stack<int> s;
    stack<int> val;
public:
    StockSpanner() {}
    
    int next(int price) {
        auto ans{1};
        while (!s.empty() && s.top() <= price) {
            ans += val.top();
            s.pop();
            val.pop();
        }
        s.push(price);
        val.push(ans);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */