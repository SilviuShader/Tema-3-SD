#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>

#define zeros(x) ( (x ^ (x - 1)) & x )

using namespace std;

const int MAX_N = 100005;

ifstream fin("baruri.in");
ofstream fout("baruri.out");

int n;
int aib[MAX_N];

void Add(int x, int capacity)
{
    for (int i = x; i <= n; i += zeros(i))
        aib[i] += capacity;
}

int Query(int x)
{
    int result = 0;
    for (int i = x; i > 0; i -= zeros(i))
        result += aib[i];

    return result;
}

void Solve()
{
    fin >> n;

    memset(aib, 0, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        int t;
        fin >> t;
        Add(i, t);
    }

    int m;
    fin >> m;
    for (int i = 0; i < m; i++)
    {
        int task;
        fin >> task;

        switch (task)
        {
        case 0:
        {
            int b, d;
            fin >> b >> d;
            int r = min(b + d, n);
            int l = max(b - d, 1);
            int result = Query(r) - Query(l - 1) - (Query(b) - Query(b - 1));
            fout << result << "\n";
        }
            break;
        case 1:
        {
            int x, b;
            fin >> x >> b;
            Add(b, x);
        }
            break;
        case 2:
        {
            int x, b;
            fin >> x >> b;
            Add(b, -x);
        }
            break;
        case 3:
        {
            int x, b1, b2;
            fin >> x >> b1 >> b2;
            Add(b1, -x);
            Add(b2, x);
        }
            break;
        }
    }
}

int main()
{
    int t;
    fin >> t;
    
    for (int i = 0; i < t; i++)
        Solve();

    fout.close();
    fin.close();

    return 0;
}