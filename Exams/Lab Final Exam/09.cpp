#include<bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals)
{
    if (intervals.empty())
    {
        return 0;
    }

    // Sort the intervals by their start time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    });

    // Create a priority queue to store the end times of meetings
    priority_queue<int, vector<int>, greater<int>> pq;

    // Add the end time of the first meeting to the priority queue
    pq.push(intervals[0][1]);

    // Iterate through the rest of the meetings
    for (int i = 1; i < intervals.size(); i++)
    {
        // If the start time of the current meeting is after the end time of the earliest meeting in the priority queue,
        // then remove the end time from the priority queue
        if (intervals[i][0] >= pq.top())
        {
            pq.pop();
        }

        // Add the end time of the current meeting to the priority queue
        pq.push(intervals[i][1]);
    }

    // The size of the priority queue is the minimum number of conference rooms needed
    return pq.size();
}

int main()
{
    vector<vector<int>> intervals1 {{0, 30}, {5, 10}, {15, 20}};
    cout << minMeetingRooms(intervals1) << endl; // Expected output: 2

    vector<vector<int>> intervals2 {{7, 10}, {2, 4}};
    cout << minMeetingRooms(intervals2) << endl; // Expected output: 1

    return 0;
}
