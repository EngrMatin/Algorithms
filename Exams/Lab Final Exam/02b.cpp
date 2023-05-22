#include <bits/stdc++.h>
using namespace std;

struct Circle
{
    int x; // x-axis position of the center
    int y; // y-axis position of the center
    int r; // radius
};

// Function to check if two circles overlap
bool doCirclesOverlap(const Circle& c1, const Circle& c2)
{
    // Calculate the distance between the centers of the circles
    int distance = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    // Check if the distance is less than or equal to the sum of the radii
    return distance <= (c1.r + c2.r);
}

// Function to find the circle group count
int findCircleGroups(const vector<Circle>& circles)
{
    int n = circles.size();
    int circleGroups = 0;
    vector<bool> visited(n, false); // To keep track of visited circles

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            circleGroups++; // Found a new circle group
            visited[i] = true; // Mark the current circle as visited

            // Explore all circles that overlap with the current circle
            for (int j = i + 1; j < n; j++)
            {
                if (!visited[j] && doCirclesOverlap(circles[i], circles[j]))
                {
                    visited[j] = true; // Mark the overlapping circle as visited
                }
            }
        }
    }

    return circleGroups;
}

int main()
{
    int n;
    //cout << "Enter the number of circles: ";
    cin >> n;

    vector<Circle> circles(n);
    //cout << "Enter the x, y, and radius for each circle: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    int circleGroups = findCircleGroups(circles);
    cout << "Number of circle groups: " << circleGroups << endl;

    return 0;
}

