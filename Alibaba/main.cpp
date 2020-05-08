#include <fstream>
#include <iostream>
#include <deque>

using namespace std;

const int MAX_N = 10005;

char line[MAX_N];

deque<int> occurences[10];

int main()
{
    ifstream fin("alibaba.in");
    int n, k;
    fin >> n >> k;
    fin >> line;
    fin.close();

    for (int i = 0; i < n; i++)
        occurences[line[i] - '0'].push_back(i);

    int remaining = n - k;

    ofstream fout("alibaba.out");

    while(remaining)
    {
        bool stop = false;
        int lastPos = 0;
        for (int i = 9; i >= 0 && !stop; i--)
        {
            if (!occurences[i].empty())
            {
                int frn = occurences[i].front();
                if (n - frn >= remaining)
                {
                    fout << i;
                    lastPos = frn;
                    stop = true;
                }
            }
        }
        for (int i = 9; i >= 0; i--)
            while (!occurences[i].empty())
                if (occurences[i].front() <= lastPos)
                    occurences[i].pop_front();
                else
                    break;
        remaining--;
    }

    fout.close();

    return 0;
}