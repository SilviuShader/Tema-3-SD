#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    FILE* fin = fopen("cautbin.in", "r");
    FILE* fout = fopen("cautbin.out", "w");

    int n;
    fscanf(fin, "%u", &n);
    uint32_t* v;
    v = new uint32_t[n];
    uint32_t mx = 1;
    for (int i = 0; i < n; i++)
    {
        fscanf(fin, "%u", &v[i]);
        mx = max(mx, v[i]);
    }

    int ix = 0;
    for (int i = 0; i < 32; i++)
        if (mx >> i & 1)
            ix = i;
    mx = 1 << (ix + 1);

    int m;
    fscanf(fin, "%d", &m);

    for (int i = 0; i < m; i++)
    {
        uint32_t task, x;
        fscanf(fin, "%u %u", &task, &x);

        int sol = 0;
        if (task == 2)
            sol = n - 1;

        for (uint32_t j = mx; j > 0; j >>= 1)
        {
            if (task != 2)
            {
                if (sol + j < n)
                    if (v[sol + j] <= x)
                        sol += j;
            }
            else
            {
                if (sol >= j)
                    if (v[sol - j] >= x)
                        sol -= j;
            }
        }

        int result = sol;
        switch (task)
        {
        case 0:
            if (v[sol] != x)
                result = -2;
        }
        fprintf(fout, "%d\n", result + 1);
    }

    fclose(fout);
    fclose(fin);
    
    return 0;
}