/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 *
 * https://leetcode.com/problems/my-calendar-ii/description/
 *
 * algorithms
 * Medium (43.38%)
 * Total Accepted:    20.3K
 * Total Submissions: 46.7K
 * Testcase Example:  '["MyCalendarTwo","book","book","book","book","book","book"]\n[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]'
 *
 * Implement a MyCalendarTwo class to store your events. A new event can be
 * added if adding the event will not cause a triple booking.
 * 
 * Your class will have one method, book(int start, int end). Formally, this
 * represents a booking on the half open interval [start, end), the range of
 * real numbers x such that start <= x < end.
 * 
 * A triple booking happens when three events have some non-empty intersection
 * (ie., there is some time that is common to all 3 events.)
 * 
 * For each call to the method MyCalendar.book, return true if the event can be
 * added to the calendar successfully without causing a triple booking.
 * Otherwise, return false and do not add the event to the calendar.
 * Your class will be called like this: MyCalendar cal = new MyCalendar();
 * MyCalendar.book(start, end)
 * 
 * Example 1:
 * 
 * 
 * MyCalendar();
 * MyCalendar.book(10, 20); // returns true
 * MyCalendar.book(50, 60); // returns true
 * MyCalendar.book(10, 40); // returns true
 * MyCalendar.book(5, 15); // returns false
 * MyCalendar.book(5, 10); // returns true
 * MyCalendar.book(25, 55); // returns true
 * Explanation: 
 * The first two events can be booked.  The third event can be double booked.
 * The fourth event (5, 15) can't be booked, because it would result in a
 * triple booking.
 * The fifth event (5, 10) can be booked, as it does not use time 10 which is
 * already double booked.
 * The sixth event (25, 55) can be booked, as the time in [25, 40) will be
 * double booked with the third event;
 * the time [40, 50) will be single booked, and the time [50, 55) will be
 * double booked with the second event.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of calls to MyCalendar.book per test case will be at most
 * 1000.
 * In calls to MyCalendar.book(start, end), start and end are integers in the
 * range [0, 10^9].
 * 
 * 
 * 
 * 
 */
class MyCalendarTwo {
public:
    map<int, vector<int>> events;
    map<int, int> collision;

    MyCalendarTwo() {
        
    }

    bool isTripleBooking(int start, int end) {
        auto it = upper_bound(collision.begin(), collision.end(), start, [] (int value, auto it) {
            return value < it.first;
        });
        bool result = false;
        if (it == collision.end()) {
            if (collision.rbegin() != collision.rend()) {
                auto prev_it = collision.rbegin();
                if (prev_it->second <= start) {
                    result = true;
                }
            } else {
                result = true;
            }
        } else {
            if (it->first >= end) {
                if (it == collision.begin()) {
                    result = true;
                } else {
                    auto prev_it = prev(it);
                    result = start >= prev_it->second;
                }
            }
        }

        return !result;
    }

    void computeOverlap(int start, int end) {
        for (auto pair : events) {
            int start_i = pair.first;
            for (auto end_i : pair.second) {
                if (start < end_i && end > start_i) {
                    collision.insert({max(start, start_i), min(end, end_i)});
                }
            }
        }

        events[start].push_back(end);
    }
    
    bool book(int start, int end) {
        if (!isTripleBooking(start, end)) {
            computeOverlap(start, end);
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

