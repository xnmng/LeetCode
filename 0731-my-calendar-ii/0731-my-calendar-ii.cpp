// https://leetcode.com/problems/my-calendar-ii/discuss/5838215/2-Approach:-Battle-of-Booking-Strategies:-Active-Interval-Maps-vs.-Direct-Overlap-Management!
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    // O(n) per book call
    bool book(int start, int end) {
        eventCount[start]++;
        eventCount[end]--;

        int ongoingEvents = 0;
        for (auto &[time, change] : eventCount) {
            ongoingEvents += change;
            if (ongoingEvents >= 3) {
                eventCount[start]--;
                eventCount[end]++;
                return false;
            }
        }
        return true;
    }

    map<int,int> eventCount;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */