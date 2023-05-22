#include<bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end()); // Sort intervals by start time

    priority_queue<int, vector<int>, greater<int>> pq; // Min heap to store end times of active meetings

    for (auto interval : intervals)
    {
        if (!pq.empty() && interval[0] >= pq.top())
        {
            pq.pop(); // Current meeting can reuse an existing room
        }
        pq.push(interval[1]); // Add end time of current meeting to active meetings
    }
    return pq.size(); // Number of active meetings is equal to number of conference rooms required
}

int main()
{
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Minimum number of conference rooms required: " << minMeetingRooms(intervals1) << endl;

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << "Minimum number of conference rooms required: " << minMeetingRooms(intervals2) << endl;

    return 0;
}
