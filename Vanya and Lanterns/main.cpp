#include <iostream>
#include <algorithm>

const int MAX_N = 1005;

using namespace std;

int distances[MAX_N];

int main()
{
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> distances[i];

    sort(distances, distances + n);

    double dist = 0.0f;
    for (int i = 1; i < n; i++)
        dist = max(dist, ((double)distances[i] - (double)distances[i - 1]) / 2.0);
    dist = max(dist, (double)distances[0]);
    dist = max(dist, (double)l - (double)distances[n - 1]);

    printf("%0.10lf", dist);

    return 0;
}