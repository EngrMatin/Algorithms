#include <bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end()); // sort intervals by start time

    int n = intervals.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (intervals[i][1] > intervals[i+1][0])  // if end time of current meeting is greater than start time of next meeting
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> intervals = {{0,30}, {5,10}, {15,20}};
    bool canAttend = canAttendMeetings(intervals);
    cout << (canAttend ? "true" : "false") << endl; // Output: false

    intervals = {{7,10}, {2,4}};
    canAttend = canAttendMeetings(intervals);
    cout << (canAttend ? "true" : "false") << endl; // Output: true

    return 0;
}

