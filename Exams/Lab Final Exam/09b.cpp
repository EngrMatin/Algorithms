#include<bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto interval : intervals)
    {
        if (!pq.empty() && interval[0] >= pq.top())
        {
            pq.pop();
        }

        pq.push(interval[1]);
    }

    return pq.size();
}

int main()
{
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Minimum number of conference rooms required: " << minMeetingRooms(intervals1) << endl;

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << "Minimum number of conference rooms required: " << minMeetingRooms(intervals2) << endl;

    return 0;
}
