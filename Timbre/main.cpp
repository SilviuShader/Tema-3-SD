#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int, int> > tickets;
priority_queue<int, vector<int>, greater<int>> priorityQueue;

int main()
{
    ifstream fin("timbre.in");
    int n, m, k;
    int remaining;
    int result = 0;
    fin >> n >> m >> k;
    
    for (int i = 0; i < m; i++)
    {
        pair<int, int> ticket;
        fin >> ticket.first >> ticket.second;
        tickets.push_back(ticket);
    }
    fin.close();

    sort(tickets.rbegin(), tickets.rend());

    remaining = n;

    for (int i = 0; i < tickets.size(); i++)
    {
        while (tickets[i].first < remaining)
        {
            result += priorityQueue.top();
            priorityQueue.pop();
            remaining -= k;
        }
        priorityQueue.push(tickets[i].second);
    }

    while (remaining > 0)
    {
        result += priorityQueue.top();
        priorityQueue.pop();
        remaining -= k;
    }

    ofstream fout("timbre.out");
    fout << result;
    fout.close();

    return 0;
}