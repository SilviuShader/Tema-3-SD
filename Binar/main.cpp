#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

const int MAX_N = 2005;

char line[MAX_N] = { NULL };
int v[MAX_N];

using namespace std;

int main()
{
    FILE* fin = fopen("binar.in" , "r");
    int n, m;
    fscanf(fin, "%d %d", &n, &m);
    
    int addedBits = 0;
    vector<uint64_t> columns[MAX_N];

    for (int i = 0; i < n; i++)
    {
        if (addedBits == 0)
            for (int j = 0; j < m; j++)
                columns[j].push_back((uint64_t)0);
        addedBits++;
        addedBits %= 64;

        fscanf(fin, "%s", line);
        for (int j = 0; j < m; j++)
        {
            uint64_t prevNum = columns[j][columns[j].size() - 1];
            prevNum = (prevNum << 1) | (line[j] - '0');
            columns[j][columns[j].size() - 1] = prevNum;
        }
    }
    fclose(fin);

    for (int i = 0; i < m; i++)
        v[i] = i;

    sort(v, v + m, [&](int a, int b)
        {
            return columns[a] < columns[b];
        });

    FILE* fout = fopen("binar.out", "w");
    for (int i = 0; i < m; i++)
        fprintf(fout, "%d ", v[i] + 1);
    fclose(fout);

    return 0;
}