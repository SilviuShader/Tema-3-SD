#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAX_N = 100005;

int n, k;
LL a[MAX_N];

LL Solve(LL x)
{
    LL result = 1e18;
    LL val = 0;
    for (int i = 0; i < n; i++)
    {
        val += abs(a[i] - x);
        if (i >= k)
            val -= abs(a[i - k] - x);
        
        if (i >= k - 1)
            result = min(result, val);
    }

    return result;
}

int main()
{
    ifstream fin("pikachu.in");

    fin >> n >> k;
    for (int i = 0; i < n; i++)
        fin >> a[i];

    fin.close();

    LL st = 0;
    LL dr = 2e9;
    while (st <= dr)
    {
        LL mid = (st + dr) >> 1;
        if (Solve(mid - 1) > Solve(mid + 1))
            st = mid + 1;
        else
            dr = mid - 1;
    }

    ofstream fout("pikachu.out");
    fout << Solve(st);
    fout.close();

    return 0;
}