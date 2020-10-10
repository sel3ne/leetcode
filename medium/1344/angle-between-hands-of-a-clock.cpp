class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;
        int h = hour * 60 + minutes;
        int m = minutes * 12;
        int d = abs(h - m);
        if (d > 360)
        {
            d = 720 - d;
        }
        return d / 2.0;
    }
};