class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto itr = mp.upper_bound(start);
        if (itr != mp.begin()) {
            --itr;
        }
        while (itr != mp.end() && itr->first < end) {
            if (hasClash(itr->first, itr->second, start, end)) {
                return false;
            }
            ++itr;
        }
        mp[start] = end;
        return true;
    }

private:
    map<int,int> mp; // [start, end]

    bool hasClash(int a, int b, int x, int y) {
        cout << a << " " << b << " " << x << " " << y << "\n";
        cout << (max(b, y) - min(a, x) < (b - a) + (y - x)) << "\n";
        return max(b, y) - min(a, x) < (b - a) + (y - x);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */