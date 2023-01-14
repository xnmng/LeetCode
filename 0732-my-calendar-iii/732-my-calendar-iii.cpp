class MyCalendarThree {
private:
    map<int,int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++mp[start];
        --mp[end];
        auto ans{0};
        auto cur{0};
        for (auto i : mp) {
            cur += i.second;
            ans = max(ans, cur);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */