#include <bits/stdc++.h>
using namespace std;

// Definition of Meeting Interval structure
struct Interval
{
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

// Function to check if a person can attend all meetings
bool canAttendMeetings(vector<Interval>& intervals)
{
    // Sort the intervals based on start time
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    });

    // Check for overlapping intervals
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start < intervals[i-1].end)
        {
            return false; // Overlapping intervals, person cannot attend all meetings
        }
    }

    return true; // No overlapping intervals, person can attend all meetings
}

int main()
{
    // Input array of meeting time intervals
    vector<Interval> intervals1 = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    vector<Interval> intervals2 = {Interval(7, 10), Interval(2, 4)};

    // Check if a person can attend all meetings
    cout << "Can a person attend all meetings in intervals1? " << (canAttendMeetings(intervals1) ? "Yes" : "No") << endl;
    cout << "Can a person attend all meetings in intervals2? " << (canAttendMeetings(intervals2) ? "Yes" : "No") << endl;

    return 0;
}
