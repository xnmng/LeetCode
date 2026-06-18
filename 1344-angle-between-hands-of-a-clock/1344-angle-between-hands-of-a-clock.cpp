class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double hourAngle = 360.0 / 12 * hour + 360.0 / 12 / 60 * minutes;
        double minuteAngle = 360 / 60 * minutes;
        // cout << hourAngle << " " << minuteAngle << "\n";
        return min(abs(hourAngle - minuteAngle), 360 - abs(hourAngle - minuteAngle));
    }
};