#include <iostream>
#include <fstream>

#define MAX_N 100005

using namespace std;

int lookup[100][MAX_N];

int main()
{
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");
    
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> lookup[0][i];
    
    int maxK = 1;
    while ((1 << maxK) <= n)
        maxK++;

    for (int i = 1; i <= maxK; i++)
    {
        for (int j = 0; (j + (1 << i) - 1) < n; j++)
        {
            if (lookup[i - 1][j] < lookup[i - 1][j + (1 << (i - 1))])
                lookup[i][j] = lookup[i - 1][j];
            else
                lookup[i][j] = lookup[i - 1][j + (1 << (i - 1))];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        fin >> x >> y;

        y--;
        x--;

        int k = 1;
        while (1 << k <= (y - x))
            k++;
        k--;

        int result = lookup[k][y - (1 << k) + 1];
        if (lookup[k][x] <= lookup[k][y - (1 << k) + 1])
            result = lookup[k][x];

        fout << result << "\n";
    }

    fout.close();
    fin.close();

    return 0;
}